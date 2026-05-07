/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:55:20 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/07 10:28:59 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	i;

	min = ft_find_min(*stack_a);
	i = 0;
	while ((*stack_a)->content != min)
	{
		ft_rotate_single(stack_a, 'a');
		i++;
	}
	ft_push_top_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_push_top_a(stack_a, stack_b);
	return (0);
}

int	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_find_min(*stack_a);
	while ((*stack_a)->content != min)
		ft_rotate_single(stack_a, 'a');
	ft_push_top_b(stack_a, stack_b);
	min = ft_find_min(*stack_a);
	while ((*stack_a)->content != min)
		ft_rotate_single(stack_a, 'a');
	ft_push_top_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	if ((*stack_b)->content < (*stack_b)->next->content)
		ft_swap_single(stack_b, 'b');
	ft_push_top_a(stack_a, stack_b);
	ft_push_top_a(stack_a, stack_b);
	return (0);
}
