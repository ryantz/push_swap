/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:07:03 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/10 16:26:54 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack ft_create_stack_element(int	content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if(!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

int ft_push_stack(t_stack **stack, t_stack *new)
{
	if (!new)
		return (1);
	new->next = *stack;
	*stack = new;
}

void	ft_print_stack(t_stack **stack)
{
	while ((*stack)->next != NULL)
	{
		ft_printf("%d\n", (*stack)->content);
		*stack = (*stack)->next;
	}
}
