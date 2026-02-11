/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:27:30 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/11 23:14:24 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*new_element;
	t_stack	*new_element2;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	i = 0;
	while (i < argc - 1)
	{
		new_element = ft_create_stack_element(ft_atoi(argv[i + 1]));
		new_element2 = ft_create_stack_element(ft_atoi(argv[i + 1]) + 1);
		ft_push_stack(&stack_a, new_element, 'e');
		ft_push_stack(&stack_b, new_element2, 'e');
		i++;
	}
	ft_printf("original stack a:\n");
	ft_print_stack(stack_a);
	ft_printf("\n");
	ft_printf("original stack b:\n");
	ft_print_stack(stack_b);
	ft_printf("\n");
	ft_printf("swapping single stack a:\n");
	ft_swap_single(&stack_a);
	ft_print_stack(stack_a);
	ft_printf("\n");
	ft_printf("swapping double stack a and b:\n");
	ft_swap_both(&stack_a, &stack_b);
	ft_printf("stack a:\n");
	ft_print_stack(stack_a);
	ft_printf("\n");
	ft_printf("stack b:\n");
	ft_print_stack(stack_b);
	return (0);
}
