*This project has been created as part of the 42 curriculum by ryatan*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 curriculum that focuses on optimizing algorithmic efficiency under strict constraints.
The goal is to sort a stack of integers using two stacks (a and b) and a limited set of operations, while producing the smallest possible number of moves.

Only the following operations are allowed:

`sa`, `sb`, `ss` – swap the top elements

`pa`, `pb` – push between stacks

`ra`, `rb`, `rr` – rotate stacks up

`rra`, `rrb`, `rrr` – rotate stacks down

The program takes a list of integers as input, validates them (no duplicates, valid range), and outputs the sequence of operations required to sort the numbers in ascending order.

## Instructions

First, make the project. This make command uses the rules in the Makefile to first compile the Makefiles in the ft_printf and libft folders in order to make use of them within this project

```bash
make
```
Then, use the executable and specify the values after

```bash
./push_swap 1 2 3 4
```

## Resources

