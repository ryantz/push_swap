/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:50:11 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/19 14:59:12 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}				t_stack;

// stack
t_stack	*ft_create_stack_element(int content);
t_stack	*ft_last_stack_element(t_stack *head);
t_stack	*ft_second_last_stack_element(t_stack *head);
int		ft_push_stack(t_stack **stack, t_stack *new_element, char end);

// helpers
void	ft_print_stack(t_stack *stack);
int		ft_ischardigit(char c);
int		ft_print_error(char *error_message);
int		ft_stack_len(t_stack *stack);

#endif
