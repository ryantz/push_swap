/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:27:30 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/07 18:27:46 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "check_errors.h"
#include "algorithm.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;
	t_stack	*new_element;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**new_argv;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_error_checks(argc) != 0 || argv[1][0] == '\0')
	{
		ft_printf("Error\n");
		return (1);
	}
	i = 0;
	while (i < argc - 1)
	{
		new_argv = ft_split(argv[i + 1], ' ');
		if (!new_argv)
			return (1);
		j = 0;
		len = 0;
		while (new_argv[len])
			len++;
		while (j < len)
		{
			if (ft_check_limits(new_argv[j]) == 1 ||
					ft_valid_number(new_argv[j]) == 1)
				return (ft_free_stack(&stack_a), free_all(new_argv),
						ft_printf("Error\n"), 1);
			new_element = ft_create_stack_element(ft_atoi(new_argv[j]));
			ft_push_stack(&stack_a, new_element, 'e');
			free(new_argv[j]);
			j++;
		}
		free(new_argv);
		i++;
	}
	ft_assign_index(stack_a);
	if (ft_check_duplicates(stack_a) == 1)
		return (ft_free_stack(&stack_a), ft_printf("Error\n"), 1);
	push_swap(&stack_a, &stack_b);
	return (0);
}
