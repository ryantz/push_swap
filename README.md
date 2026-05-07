*This project has been created as part of the 42 curriculum by ryatan*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 curriculum that focuses on optimizing algorithmic efficiency under strict constraints. The goal is to sort a stack of integers using two stacks (a and b) and a limited set of operations, while producing the smallest possible number of moves.

Only the following operations are allowed:

- `sa`, `sb`, `ss` – swap the top two elements of stack a, b, or both
- `pa`, `pb` – push the top element between stacks
- `ra`, `rb`, `rr` – rotate stacks upward (first element becomes last)
- `rra`, `rrb`, `rrr` – reverse rotate stacks downward (last element becomes first)

The program takes a list of integers as input, validates them (no duplicates, valid integer range), and outputs the sequence of operations required to sort the numbers in ascending order.

### Algorithm choices

| Input size | Algorithm used |
|---|---|
| 2 elements | Direct swap if needed |
| 3 elements | Hardcoded decision tree (≤ 2 ops) |
| 4 elements | Push min to b, sort 3, push back |
| 5 elements | Push two mins to b, sort 3, push back |
| 6+ elements | Radix sort on compressed indices |

For larger inputs, values are first compressed to indices (0 to n−1) using a selection-based ranking pass, then sorted bit-by-bit using LSD radix sort. This gives consistent performance well within the benchmark limits.

## Instructions

Clone the repository and run `make` at the root. This compiles `libft` and `ft_printf` from their respective subdirectories before linking the main binary.

```bash
make
```

Run the program with integers as arguments (first argument = top of stack):

```bash
./push_swap 3 1 4 1 5       # Error: duplicate
./push_swap 0 one 2 3       # Error: not an integer
./push_swap 5 3 1 4 2       # outputs sorted sequence of operations
```

To verify correctness, pipe the output into the provided checker:

```bash
ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker_OS $ARG
```

To count operations:

```bash
ARG="5 3 1 4 2"; ./push_swap $ARG | wc -l
```

Other Makefile rules:

```bash
make clean      # remove object files
make fclean     # remove object files and binary
make re         # fclean + make
```

## Resources

### References

- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Push_swap visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer) — useful for debugging operation sequences
- [42 push_swap tester by gemartin99](https://github.com/gemartin99/Push-Swap-Tester)

### AI usage

Claude (claude.ai) was consulted during this project for the following:

- Generating and refining this README to meet the subject's requirements
