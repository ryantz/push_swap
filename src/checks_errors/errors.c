/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:03:06 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/07 10:39:16 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_errors.h"

int	ft_check_input(int argc, char **argv);
int	ft_check_arg_count(int argc);
int	ft_check_limits(char *string_nb);
int	ft_valid_number(char *str);

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

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (ft_print_error("Error\n"), 1);
		if (ft_check_limits(argv[i]) == 1)
			return (ft_print_error("Error\n"), 1);
		if (ft_valid_number(argv[i]))
			return (ft_print_error("Error\n"), 1);
		i++;
	}
	return (0);
}

int	ft_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (!str[i])
			return (1);
	}
	while (str[i])
	{
		if (ft_ischardigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_limits(char *string_nb)
{
	long	nb;
	int		sign;
	int		digit;

	nb = 0;
	sign = 1;
	if (*string_nb == '-')
	{
		sign = -1;
		string_nb++;
	}
	while (*string_nb)
	{
		digit = *string_nb - '0';
		if (nb > (2147483647 - digit) / 10)
			return (1);
		nb = nb * 10 + digit;
		string_nb++;
	}
	if (sign == -1 && nb > 2147483648L)
		return (1);
	return (0);
}
