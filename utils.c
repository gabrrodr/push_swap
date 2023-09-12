/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:19:53 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/12 14:35:42 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_stack **stack)
{
	t_stack	*max_v;
	t_stack	*compare;
	t_stack	*last;

	max_v = (*stack);
	compare = max_v->next;
	last = ps_lstlast((*stack));
	while (max_v && compare)
	{
		if ((int)(long)max_v->content < (int)(long)compare->content)
			max_v = compare;
		else
			compare = compare->next;
	}
	if ((int)(long)max_v->content < (int)(long)last->content)
		max_v = last;
	return (max_v->content);
}

int	find_min_value(t_stack **stack)
{
	t_stack	*min_v;
	t_stack	*compare;
	t_stack	*last;

	min_v = (*stack);
	compare = min_v->next;
	last = ps_lstlast(*stack);
	while (min_v && compare)
	{
		if ((int)(long)min_v->content > (int)(long)compare->content)
			min_v = compare;
		else
			compare = compare->next;
	}
	if ((int)(long)min_v->content > (int)(long)last->content)
		min_v = last;
	return (min_v->content);
}

int	check_sorted(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	while (node)
	{
		if (node->next && 
			(int)(long)(node)->content > (int)(long)(node)->next->content)
		{
			return (0);
		}
		(node) = (node)->next; 
	}
	return (1);
}

int	check_rev_sorted(t_stack **stack)
{
	int		i;
	t_stack	*node;

	node = (*stack);
	i = (int)(long)(node)->content;
	while (node)
	{
		if (i < (int)(long)(node)->content)
		{
			return (0);
		}
		i = (int)(long)(node)->content;
		(node) = (node)->next; 
	}
	return (1);
}

long	ps_atol(const char *nptr)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}
