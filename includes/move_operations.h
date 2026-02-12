/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:27:28 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/12 11:27:28 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_OPERATIONS_H
# define MOVE_OPERATIONS_H

# include "push_swap.h"

// swap operations
int		ft_swap_single(t_stack **stack);
int		ft_swap_both(t_stack **stack_a, t_stack **stack_b);
int		ft_push_top_b(t_stack **stack_a, t_stack **stack_b);
int		ft_push_top_a(t_stack **stack_a, t_stack **stack_b);

// rotate operations
int		ft_rotate_single(t_stack **stack);
int		ft_rotate_both(t_stack **stack_a, t_stack **stack_b);
int		ft_reverse_rotate_single(t_stack **stack);
int		ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
