/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:00:52 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/11 11:17:12 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *sorted)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = sorted;
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

int	find_index(int n, t_stack *sorted)
{
	int	i;

	i = 0;
	while (sorted)
	{
		if (n == sorted->content)
		{
			break ;
		}
		sorted = sorted->next;
		i++;
	}
	return (i);
}
