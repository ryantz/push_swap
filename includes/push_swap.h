/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:50:11 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/11 23:12:21 by ryatan           ###   ########.fr       */
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
t_stack *ft_create_stack_element(int content);
int		ft_push_stack(t_stack **stack, t_stack *new_element, char end);
int		ft_swap_single(t_stack **stack);
int		ft_swap_both(t_stack **stack_a, t_stack **stack_b);

// helpers
void	ft_print_stack(t_stack *stack);

#endif
