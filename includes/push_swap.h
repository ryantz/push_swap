/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:50:11 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/10 16:27:45 by ryatan           ###   ########.fr       */
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
t_stack ft_create_stack_element(int	content);
int		ft_push_stack(t_stack **stack, t_stack *new);

void	ft_print_stack(t_stack **stack);
int 	ft_push_stack(t_stack **stack, t_stack *new);
t_stack ft_create_stack_element(int	content);

//int	ft_print_stacks(int *stack_a, int *stack_b, int argc);
//int	ft_swap(int **stack);
//int	ft_swap_both(int **stack_a, int **stack_b);

#endif
