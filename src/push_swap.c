/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:03:54 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/08 22:43:14 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_errors.h"
#include "algorithm.h"

int	process_argv(char **new_argv, t_stack **stack_a);

int	init_stack_from_input(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**new_argv;

	i = 0;
	while (i < argc - 1)
	{
		new_argv = ft_split(argv[i + 1], ' ');
		if (!new_argv || process_argv(new_argv, stack_a))
			return (1);
		i++;
	}
	return (0);
}

int	process_argv(char **new_argv, t_stack **stack_a)
{
	int		j;
	int		len;
	t_stack	*new_element;

	j = 0;
	len = ft_find_len(new_argv);
	while (j < len)
	{
		if (ft_check_limits(new_argv[j]) || ft_valid_number(new_argv[j]))
			return (free_all(new_argv), 1);
		new_element = ft_create_stack_element(ft_atoi(new_argv[j]));
		if (!new_element)
			return (free_all(new_argv), 1);
		ft_push_stack(stack_a, new_element, 'e');
		free(new_argv[j]);
		j++;
	}
	return (free(new_argv), 0);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_len(*stack_a);
	if (ft_is_sorted(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return ;
	}
	if (size == 2)
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_radix(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
