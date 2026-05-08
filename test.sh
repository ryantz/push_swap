#!/bin/bash

# ============================================================
#  push_swap — Eval Test Suite
# ============================================================

GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[0;33m"
CYAN="\033[0;36m"
RESET="\033[0m"

PASS=0
FAIL=0

pass() { echo -e "${GREEN}[PASS]${RESET} $1"; ((PASS++)); }
fail() { echo -e "${RED}[FAIL]${RESET} $1"; ((FAIL++)); }
header() { echo -e "\n${CYAN}══ $1 ══${RESET}"; }

# ── helpers ────────────────────────────────────────────────

expect_silent() {
  local desc="$1"; shift
  local out err
  out=$("$@" 2>/tmp/ps_err)
  err=$(cat /tmp/ps_err)
  if [[ -z "$out" && -z "$err" ]]; then pass "$desc"
  else fail "$desc (stdout='$out' stderr='$err')"; fi
}

expect_ok() {
  local desc="$1"; shift
  local result
  result=$(./push_swap "$@" | ./checker_linux "$@" 2>&1)
  if [[ "$result" == "OK" ]]; then pass "$desc"
  else fail "$desc (got '$result')"; fi
}

expect_ok_arg() {
  # For cases where ARG is a single pre-built string
  local desc="$1"
  local arg="$2"
  local result
  result=$(./push_swap $arg | ./checker_linux $arg 2>&1)
  if [[ "$result" == "OK" ]]; then pass "$desc"
  else fail "$desc (got '$result')"; fi
}

expect_error() {
  local desc="$1"; shift
  local err
  err=$(./push_swap "$@" 2>&1 >/dev/null)
  if [[ "$err" == "Error" ]]; then pass "$desc"
  else fail "$desc (stderr='$err')"; fi
}

expect_op_count() {
  local desc="$1"
  local arg="$2"
  local limit="$3"
  local count
  count=$(./push_swap $arg | wc -l)
  if (( count < limit )); then pass "$desc (ops=$count < $limit)"
  else fail "$desc (ops=$count >= $limit)"; fi
}

# ── 0. Setup ───────────────────────────────────────────────

header "0. Setup"
if make 2>&1 | grep -q "Error"; then
  echo -e "${RED}[FAIL]${RESET} make failed — aborting"; exit 1
fi
pass "make"
chmod +x checker_linux 2>/dev/null
[[ -x ./push_swap    ]] && pass "push_swap is executable" || { fail "push_swap not found"; exit 1; }
[[ -x ./checker_linux ]] && pass "checker_linux is executable" || { fail "checker_linux not found"; exit 1; }

# ── 1. No Arguments ────────────────────────────────────────

header "1. No Arguments"
expect_silent "no args" ./push_swap

# ── 2. Single Argument ─────────────────────────────────────

header "2. Single Argument"
expect_silent "single arg: 1"   ./push_swap 1
expect_silent "single arg: \"1\"" ./push_swap "1"

# ── 3. Already Sorted ──────────────────────────────────────

header "3. Already Sorted — No Output"
expect_silent "sorted: 1 2 3"       ./push_swap 1 2 3
expect_silent "sorted: 1 2 3 4 5"   ./push_swap 1 2 3 4 5
expect_silent "sorted: \"1 2 3\""   ./push_swap "1 2 3"

# ── 4. Basic Sort with Checker ─────────────────────────────

header "4. Basic Sort with Checker"
expect_ok_arg "sort: 3 2 1"       "3 2 1"
expect_ok_arg "sort: 5 4 3 2 1"   "5 4 3 2 1"
expect_ok_arg "sort: 3 5 1 2 4"   "3 5 1 2 4"

# ── 5. Quoted / Mixed String Arguments ─────────────────────

header "5. Quoted / Mixed String Arguments"
ARG="3 5 1 2 4"
r1=$(./push_swap "3 5" 1 2 4    | ./checker_linux $ARG 2>&1)
r2=$(./push_swap "3 5 1" 2 4    | ./checker_linux $ARG 2>&1)
r3=$(./push_swap "3 5 1 2 4"    | ./checker_linux $ARG 2>&1)
[[ "$r1" == "OK" ]] && pass "mixed: \"3 5\" 1 2 4"     || fail "mixed: \"3 5\" 1 2 4 (got '$r1')"
[[ "$r2" == "OK" ]] && pass "mixed: \"3 5 1\" 2 4"     || fail "mixed: \"3 5 1\" 2 4 (got '$r2')"
[[ "$r3" == "OK" ]] && pass "mixed: \"3 5 1 2 4\""     || fail "mixed: \"3 5 1 2 4\" (got '$r3')"

# ── 6. Error Cases ─────────────────────────────────────────

header "6. Error Cases"
expect_error "error: abc"         abc
expect_error "error: \"abc\""     "abc"
expect_error "error: 1 2 abc"     1 2 abc
expect_error "error: ++1"         ++1
expect_error "error: +-1"         +-1
expect_error "error: +"          +
expect_error "error: -"          -
expect_error "error: \"\""        ""
expect_error "error: \" \""       " "

# ── 7. Duplicates ──────────────────────────────────────────

header "7. Duplicates"
expect_error "dup: 1 2 2"          1 2 2
expect_error "dup: 1 1 1"          1 1 1
expect_error "dup: \"1 2 2\""      "1 2 2"
expect_error "dup: \"1 2\" 2"      "1 2" 2

# ── 8. Integer Overflow ────────────────────────────────────

header "8. Integer Overflow"
expect_error "overflow:  2147483648"           2147483648
expect_error "overflow: -2147483649"          -2147483649
expect_error "overflow:  99999999999"          99999999999
expect_error "overflow:  2147483647 2147483648" 2147483647 2147483648

# ── 9. INT_MIN and INT_MAX ─────────────────────────────────

header "9. INT_MIN / INT_MAX"
ARG="2147483647 -2147483648 0"
expect_ok_arg "INT_MIN/MAX sort" "$ARG"

# ── 10. 2 and 3 Numbers ────────────────────────────────────

header "10. 2 and 3 Numbers"
expect_ok_arg "2-num: 2 1"     "2 1"
expect_ok_arg "3-num: 3 1 2"   "3 1 2"
expect_ok_arg "3-num: 2 3 1"   "2 3 1"
expect_ok_arg "3-num: 3 2 1"   "3 2 1"

# ── 11. 100 Numbers ────────────────────────────────────────

header "11. 100 Numbers"
ARG="-2147483648 0 $(shuf -i 1-2147483647 -n 98 | tr '\n' ' ')"
expect_op_count "100 nums ops < 700  (100%)" "$ARG" 700
expect_op_count "100 nums ops < 1100 (80%)"  "$ARG" 1100
result=$(./push_swap $ARG | ./checker_linux $ARG 2>&1)
[[ "$result" == "OK" ]] && pass "100 nums: checker OK" || fail "100 nums: checker got '$result'"

# ── 12. 500 Numbers ────────────────────────────────────────

header "12. 500 Numbers"
ARG="-2147483648 0 $(shuf -i 1-2147483647 -n 498 | tr '\n' ' ')"
expect_op_count "500 nums ops < 5500 (100%)" "$ARG" 5500
expect_op_count "500 nums ops < 8500 (80%)"  "$ARG" 8500
result=$(./push_swap $ARG | ./checker_linux $ARG 2>&1)
[[ "$result" == "OK" ]] && pass "500 nums: checker OK" || fail "500 nums: checker got '$result'"

# ── 13. Valgrind ───────────────────────────────────────────

header "13. Valgrind — No Memory Leaks"
if ! command -v valgrind &>/dev/null; then
  echo -e "${YELLOW}[SKIP]${RESET} valgrind not installed"
else
  vg_check() {
    local desc="$1"; shift
    local out
    out=$(valgrind --leak-check=full --show-leak-kinds=all ./push_swap "$@" 2>&1)
    if echo "$out" | grep -q "0 bytes in 0 blocks"; then pass "valgrind: $desc"
    else fail "valgrind: $desc"; echo "$out" | grep -E "definitely|indirectly|possibly|ERROR"; fi
  }
  vg_check "3 2 1"           3 2 1
  vg_check "\"3 5\" 1 2 4"   "3 5" 1 2 4
  vg_check "\"3 5 1 2 4\""   "3 5 1 2 4"
  vg_check "abc"             abc
  vg_check "1 2 2"           1 2 2
  vg_check "2147483648"      2147483648
  vg_check "\"\""            ""
  vg_check "\"1 2\" 2"       "1 2" 2
fi

# ── 14. Negative Numbers ───────────────────────────────────

header "14. Negative Numbers"
expect_ok_arg "neg: -5 -3 -1 -4 -2" "-5 -3 -1 -4 -2"
expect_ok_arg "neg: -1 0 1"          "-1 0 1"

# ── 15. Makefile Checks ────────────────────────────────────

header "15. Makefile"
out=$(make 2>&1)
if echo "$out" | grep -qiE "Nothing to be done|is up to date"; then
  pass "make: no relink on second call"
else
  fail "make: relinked when it shouldn't (output: $out)"
fi
make clean  &>/dev/null && pass "make clean"  || fail "make clean"
make fclean &>/dev/null && pass "make fclean" || fail "make fclean"
make re     &>/dev/null && pass "make re"     || fail "make re"

# ── Summary ────────────────────────────────────────────────

echo -e "\n${CYAN}══ Results ══${RESET}"
TOTAL=$((PASS + FAIL))
echo -e "  Total : $TOTAL"
echo -e "  ${GREEN}Passed${RESET} : $PASS"
echo -e "  ${RED}Failed${RESET} : $FAIL"
[[ $FAIL -eq 0 ]] && echo -e "\n${GREEN}All tests passed!${RESET}\n" \
                  || echo -e "\n${RED}$FAIL test(s) failed.${RESET}\n"
exit $FAIL
