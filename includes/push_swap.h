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

// helpers
void	ft_print_stack(t_stack *stack);

#endif
