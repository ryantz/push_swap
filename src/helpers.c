/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:48:15 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/03 09:03:20 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ischardigit(char c)
{
	if (c < '0' || c > '9')
		return (1);
	return (0);
}

int	ft_print_error(char *error_message)
{
	size_t	error_message_len;

	if (!error_message)
		return (1);
	error_message_len = ft_strlen(error_message);
	write(2, error_message, error_message_len);
	return (0);
}

int	ft_stack_len(t_stack *stack)
{
	int	stack_len;

	stack_len = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		stack_len++;
		stack = stack->next;
	}
	return (stack_len);
}

int ft_find_min(t_stack *stack)
{
    int min;

    min = stack->content;
    while (stack)
    {
        if (stack->content < min)
            min = stack->content;
        stack = stack->next;
    }
    return (min);
}

int ft_is_sorted(t_stack *stack)
{
    while (stack->next)
    {
        if (stack->content > stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}
