/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:03:06 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/07 18:28:11 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_errors.h"
int	ft_check_input(int argc, char **argv);
int	ft_check_arg_count(int argc);

int	ft_error_checks(int argc)
{
	if (ft_check_arg_count(argc) == 1)
		return (1);
	return (0);
}

int	ft_check_arg_count(int argc)
{
	if (argc < 2)
		return (1);
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
	long	limit;

	nb = 0;
	sign = 1;
	if (*string_nb == '-')
	{
		sign = -1;
		string_nb++;
	}
	limit = 2147483647L + (sign == -1);
	while (*string_nb)
	{
		digit = *string_nb - '0';
		if (nb > (limit - digit) / 10)
			return (1);
		nb = nb * 10 + digit;
		string_nb++;
	}
	return (0);
}
