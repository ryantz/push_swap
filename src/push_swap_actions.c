/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:55:52 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/10 20:17:08 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa, sb
int	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
	{
		ft_printf("Do nothing\n");
		return (1);
	}
	tmp = (*stack)->next;
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = tmp;
	return (0);
}

//ss
int	ft_swap_both(int **stack_a, int **stack_b)
{
	if (!*stack_a || !*stack_b || !(*stack_a)[1] || !(*stack_b)[1])
	{
		ft_printf("Do nothing\n");
		return (1);
	}
	ft_swap(stack_a);
	ft_swap(stack_b);
	return (0);
}

//pa
//pb
int	ft_push(int **stack_a, int **stack_b, char to_dir)
{
	int	tmp;

	tmp = 0;
	if (!*stack_a || !*stack_b || !to_dir)
		return (1);
	if (to_dir == 'a')
	{
		tmp = (*stack_a)[0];
		(*stack_b)[0] = tmp;
	}
	else if (to_dir == 'b')
	{
	}
	return (0);
}
