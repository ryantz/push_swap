/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:50:08 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/20 18:50:09 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

static int	ft_sort_three_logic(t_stack **stack_a, t_stack *first,
				t_stack *second, t_stack *third);

int	ft_sort_two(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

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
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack_a || !*stack_a)
		return (1);
	first = *stack_a;
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	ft_sort_three_logic(stack_a, first, second, third);
	return (0);
}

static int	ft_sort_three_logic(t_stack **stack_a, t_stack *first
		, t_stack *second, t_stack *third)
{
	if (first->content > second->content && first->content < third->content
		&& second->content < third->content)
		ft_swap_single(stack_a);
	else if (first->content > second->content
		&& second->content > third->content)
	{
		ft_rotate_single(stack_a);
		ft_swap_single(stack_a);
	}
	else if (first->content < second->content
		&& second->content > third->content
		&& third->content > first->content)
	{
		ft_reverse_rotate_single(stack_a);
		ft_swap_single(stack_a);
	}
	else if (second->content > third->content
		&& third->content < first->content
		&& first->content < second->content)
		ft_reverse_rotate_single(stack_a);
	else if (first->content > second->content
		&& second->content < third->content
		&& third->content < first->content)
		ft_rotate_single(stack_a);
	return (0);
}

//int	ft_sort_four(t_stack **stack_a)
//{
//}
//
//int	ft_sort_five(t_stack **stack_a)
//{
//}
