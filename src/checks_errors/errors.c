/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:03:06 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/07 09:32:22 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_errors.h"

int	ft_check_input(int argc, char **argv);
int	ft_check_arg_count(int argc);
int	ft_check_limits(char *string_nb);

int	ft_error_checks(int argc, char **argv)
{
	if (ft_check_arg_count(argc) == 1)
		return (1);
	if (ft_check_input(argc, argv) == 1)
		return (1);
	if (ft_check_duplicates(argc, argv) == 1)
		return (ft_print_error("Error\n"), 1);
	return (0);
}

int	ft_check_arg_count(int argc)
{
	if (argc < 2)
		return (1);
	return (0);
}

int	ft_check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (ft_print_error("Error\n"), 1);
		if (ft_check_limits(argv[i]) == 1)
			return (ft_print_error("Error\n"), 1);
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
			{
				j++;
				if (!argv[i][j] || ft_ischardigit(argv[i][j]))
					return (ft_print_error("Error\n"), 1);
			}
			else if (ft_ischardigit(argv[i][j]))
				return (ft_print_error("Error\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_limits(char *string_nb)
{
	long	nb;
	int		sign;
	
	nb = 0;
	sign = 1;
	if (*string_nb == '-')
	{
		sign = -1;
		string_nb++;
	}
	while (*string_nb)
	{
		nb = nb * 10 + (*string_nb - '0');
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (1);
		string_nb++;
	}
	return (0);
}
