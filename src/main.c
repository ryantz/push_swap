/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:27:30 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/10 13:35:51 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	i;
	
	stack_a = malloc(sizeof(int) * (argc - 1));
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(int) * (argc - 1));
	if (!stack_a)
		return (1);
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		stack_b[i] = ft_atoi(argv[i + 1]) + 2;
		i++;
	}
	ft_print_stacks(stack_a, stack_b, argc);
	ft_swap(&stack_a);
	ft_print_stacks(stack_a, stack_b, argc);
	ft_swap(&stack_b);
	ft_print_stacks(stack_a, stack_b, argc);
	ft_swap_both(&stack_a, &stack_b);
	ft_print_stacks(stack_a, stack_b, argc);
	free(stack_a);
	free(stack_b);
	return (0);
}
