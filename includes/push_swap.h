/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:50:11 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/08 22:43:28 by ryatan           ###   ########.fr       */
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
void	ft_assign_index(t_stack *stack);

// helpers
void	ft_print_stack(t_stack *stack);
int		ft_ischardigit(char c);
int		ft_print_error(char *error_message);
int		ft_stack_len(t_stack *stack);
int		ft_find_min(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
void	ft_free_stack(t_stack **stack_a);

void	push_swap(t_stack **stack_a, t_stack **stack_b);
int		ft_stacksize(t_stack *lst);
void	free_all(char **arr);
int		ft_find_len(char **arr);
int		init_stack_from_input(int argc, char **argv, t_stack **stack_a);

#endif
