/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:55:52 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/11 23:20:08 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa, sb
int	ft_swap_single(t_stack **stack)
{
	t_stack	*first_element;
	t_stack	*second_element;
	t_stack	*third_element;
	
	if (!*stack || !(*stack)->next)
		return (0);
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
