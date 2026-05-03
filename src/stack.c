/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:07:03 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/03 08:31:43 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_stack_element(int content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
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

t_stack	*ft_second_last_stack_element(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next->next != NULL)
		head = head->next;
	return (head);
}

int	ft_push_stack(t_stack **stack, t_stack *new_element, char end)
{
	t_stack	*ptr_last;

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

void	ft_assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;
	int		index;
	int		size;

	size = ft_stack_len(stack);
	index = 0;
	while (index < size)
	{
		current = stack;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1)
			{
				if (!min_node || current->content < min_node->content)
					min_node = current;
			}
			current = current->next;
		}
		if (min_node)
			min_node->index = index;
		index++;
	}
}
