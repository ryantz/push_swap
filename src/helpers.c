/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:04:58 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/09 16:10:05 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_input_to_stack(int **stack_a, int argc)
{
	while (i < argc - 1)
	{
		(*stack_a)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (*stack_a);
}

int	ft_print_stacks(char *stack_a, char *stack_b)
{
	return (0);
}
