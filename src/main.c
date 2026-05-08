/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:27:30 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/08 22:47:01 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_errors.h"
#include "algorithm.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_check_arg_count(argc) != 0)
		return (1);
	if (ft_check_empty(argc, argv) != 0)
		return (ft_print_error("Error\n"), 1);
	if (init_stack_from_input(argc, argv, &stack_a))
		return (ft_free_stack(&stack_a), ft_print_error("Error\n"), 1);
	ft_assign_index(stack_a);
	if (ft_check_duplicates(stack_a) == 1)
		return (ft_free_stack(&stack_a), ft_print_error("Error\n"), 1);
	push_swap(&stack_a, &stack_b);
	return (0);
}
