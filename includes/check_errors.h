/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:59:42 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/08 21:53:54 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERRORS_H
# define CHECK_ERRORS_H

# include "push_swap.h"

int	ft_check_arg_count(int argc);
int	ft_check_duplicates(t_stack *stack);
int	ft_check_limits(char *string_nb);
int	ft_valid_number(char *str);
int	ft_check_empty(int argc, char **argv);

#endif
