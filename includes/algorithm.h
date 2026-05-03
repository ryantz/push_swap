/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:25:49 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/03 08:40:39 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "push_swap.h"
# include "move_operations.h"

int	ft_sort_two(t_stack **stack_a);
int	ft_sort_three(t_stack **stack_a);
int ft_sort_four(t_stack **stack_a, t_stack **stack_b);
int ft_sort_five(t_stack **stack_a, t_stack **stack_b);
int	ft_sort_radix(t_stack **stack_a, t_stack **stack_b);

#endif
