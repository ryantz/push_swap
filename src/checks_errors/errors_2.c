/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:03:21 by ryatan            #+#    #+#             */
/*   Updated: 2026/05/07 18:22:35 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_errors.h"

int	ft_check_duplicates(t_stack *stack)
{
	int	len;
	int	i;
	int	j;
	int	counter;
	int	*track;
	t_stack *ptr;

	len = ft_stacksize(stack);
	track = malloc(len * sizeof(int));
	i = 0;
	ptr = stack;
	while (i < len)
	{
		track[i] = ptr->content;
		ptr = ptr->next;
		i++;
	}
	i = 0;
	ptr = stack;
	while (i < len)
	{
		j = 0;
		counter = 0;
		while (j < len)
		{
			if (ptr->content == track[j])
				counter++;
			if (counter > 1)
				return (free(track), 1);
			j++;
		}
		ptr = ptr->next;
		i++;
	}
	return (free(track), 0);
}
