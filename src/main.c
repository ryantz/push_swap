/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:27:30 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/20 17:43:50 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checks_errors.h"
#include "algorithm.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*new_element;
	t_stack	*stack_a;
	//t_stack	*stack_b;

	stack_a = NULL;
	//stack_b = NULL;
	if (ft_error_checks(argc, argv) != 0)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		new_element = ft_create_stack_element(ft_atoi(argv[i + 1]));
		ft_push_stack(&stack_a, new_element, 'e');
		i++;
	}
	ft_printf("original stack a:\n");
	ft_print_stack(stack_a);
	ft_sort_three(&stack_a);
	ft_print_stack(stack_a);
	return (0);
}
