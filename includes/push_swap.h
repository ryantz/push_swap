/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:50:11 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/12 11:05:12 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}				t_stack;

// stack
t_stack	*ft_create_stack_element(int content);
t_stack	*ft_last_stack_element(t_stack *head);
t_stack	*ft_second_last_stack_element(t_stack *head);
int		ft_push_stack(t_stack **stack, t_stack *new_element, char end);

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

// helpers
void	ft_print_stack(t_stack *stack);

#endif
