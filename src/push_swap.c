/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:03:54 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/05 15:17:59 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algorithm.h"

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
