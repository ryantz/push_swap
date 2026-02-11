/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:07:03 by ryatan            #+#    #+#             */
/*   Updated: 2026/02/11 23:19:00 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_create_stack_element(int content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if(!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

t_stack	*ft_last_stack_element(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int ft_push_stack(t_stack **stack, t_stack *new_element, char end)
{
	t_stack *ptr_last;

	ptr_last = *stack;
	if (!stack || !new_element || (end != 'f' && end != 'e'))
		return (1);
	if (!*stack)
	{
		*stack = new_element;
		new_element->next = NULL;
		return (0);
	}
	if (end == 'f')
	{
		new_element->next = *stack;
		*stack = new_element;
	}
	else if (end == 'e')
	{
		ptr_last = ft_last_stack_element(ptr_last);
		ptr_last->next = new_element;
		new_element->next = NULL;
	}
	return (0);
}
