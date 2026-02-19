/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:27:25 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/19 15:11:30 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	ft_sort_two(t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;

	if (!stack_a)
		return (1);
	first = *stack_a;
	second = (*stack_a)->next;
	if (first->content > second->content)
		ft_swap_single(stack_a);
	return (0);
}

int	ft_sort_three(t_stack **stack_a)
{
}

int	ft_sort_four(t_stack **stack_a)
{
}

int	ft_sort_five(t_stack **stack_a)
{
}
