#include "algorithm.h"

int	ft_sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	size = ft_stack_len(*stack_a);
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->index >> bit) & 1)
				ft_rotate_single(stack_a, 'a');
			else
				ft_push_top_b(stack_a, stack_b);
			i++;
		}
		while (*stack_b)
			ft_push_top_a(stack_a, stack_b);
		bit++;
	}
	return (0);
}
