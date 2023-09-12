/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:54:16 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/11 12:08:21 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

void	free_data(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

	node = (*stack);
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

void	free_copy(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_content(t_stack **a, t_stack **b, t_stack **dupe_pos)
{
	if (a)
	{
		free_data(a);
	}
	if (b)
	{
		free_data(b);
	}
	if (dupe_pos)
	{
		free_data(dupe_pos);
	}
}
