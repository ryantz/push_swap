/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:03:21 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/08 22:31:18 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_errors.h"

void	create_tracker(int	**track, t_stack *stack);

int	ft_check_duplicates(t_stack *stack)
{
	int		i;
	int		j;
	int		counter;
	int		*tracker;
	t_stack	*ptr;

	create_tracker(&tracker, stack);
	if (!tracker)
		return (1);
	i = 0;
	ptr = stack;
	while (i < ft_stacksize(stack))
	{
		j = 0;
		counter = 0;
		while (j < ft_stacksize(stack))
		{
			if (ptr->content == tracker[j])
				counter++;
			if (counter > 1)
				return (free(tracker), 1);
			j++;
		}
		ptr = ptr->next;
		i++;
	}
	return (free(tracker), 0);
}

void	create_tracker(int	**track, t_stack *stack)
{
	int		len;
	int		i;
	t_stack	*ptr;

	ptr = stack;
	len = ft_stacksize(stack);
	*track = malloc(len * sizeof(int));
	if (!*track)
		return ;
	i = 0;
	while (i < len)
	{
		(*track)[i] = ptr->content;
		ptr = ptr->next;
		i++;
	}
}
