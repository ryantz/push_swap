/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:59:46 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/12 11:01:22 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_operations.h"

//ra, rb
int	ft_rotate_single(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return (1);
	last = ft_last_stack_element(*stack);
	first = *stack;
	second = (*stack)->next;
	last->next = first;
	first->next = NULL;
	*stack = second;
	return (0);
}

//rr
int	ft_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_single(stack_a);
	ft_rotate_single(stack_b);
	return (0);
}

//rra, rrb
int	ft_reverse_rotate_single(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return (1);
	last = ft_last_stack_element(*stack);
	second_last = ft_second_last_stack_element(*stack);
	first = *stack;
	last->next = first;
	*stack = last;
	second_last->next = NULL;
	return (0);
}

//rrr
int	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_single(stack_a);
	ft_reverse_rotate_single(stack_b);
	return (0);
}
