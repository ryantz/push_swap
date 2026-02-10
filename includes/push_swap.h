/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:50:11 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/10 13:10:34 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf.h"
#include "libft.h"

int	ft_print_stacks(int *stack_a, int *stack_b, int argc);
int	ft_swap(int **stack);
int	ft_swap_both(int **stack_a, int **stack_b);

#endif
