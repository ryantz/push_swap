/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:55:52 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/12 11:01:40 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_operations.h"

//sa, sb
int	ft_swap_single(t_stack **stack)
{
	t_stack	*first_element;
	t_stack	*second_element;
	t_stack	*third_element;

	if (!*stack || !(*stack)->next)
		return (1);
	first_element = *stack;
	second_element = (*stack)->next;
	third_element = (*stack)->next->next;
	*stack = second_element;
	second_element->next = first_element;
	first_element->next = third_element;
	return (0);
}

int	ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_single(stack_a);
	ft_swap_single(stack_b);
	return (0);
}

int	ft_push_top_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*second_a;

	if (!*stack_a || !stack_a || !stack_b)
		return (1);
	first_a = *stack_a;
	first_b = *stack_b;
	second_a = (*stack_a)->next;
	first_a->next = first_b;
	*stack_a = second_a;
	*stack_b = first_a;
	return (0);
}

int	ft_push_top_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if (!*stack_b || !stack_a || !stack_b)
		return (1);
	first_a = *stack_a;
	first_b = *stack_b;
	second_b = (*stack_b)->next;
	first_b->next = first_a;
	*stack_b = second_b;
	*stack_a = first_b;
	return (0);
}
