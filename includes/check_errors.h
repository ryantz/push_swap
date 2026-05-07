/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:59:42 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/07 18:02:22 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERRORS_H
# define CHECK_ERRORS_H

# include "push_swap.h"

int	ft_error_checks(int argc);
int	ft_check_duplicates(t_stack *stack);
int	ft_check_limits(char *string_nb);
int	ft_valid_number(char *str);

#endif
