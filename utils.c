/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:19:53 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/29 18:34:38 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*find_max_value(t_stack **stack)
{
	t_stack	*max_v;
	t_stack	*compare;
	t_stack	*last;
	
	max_v = (*stack);
	compare = max_v->next;
	last = ps_lstlast(*stack);
	
	while (max_v && compare)
	{
		if (max_v->content < compare->content)
			max_v = compare;
		else
			compare = compare->next;
	}
	if (max_v->content < last->content)
		max_v = last;
	return (max_v->content);
}

void	*find_min_value(t_stack **stack)
{
	t_stack	*min_v;
	t_stack	*compare;
	t_stack	*last;
	
	min_v = (*stack);
	compare = min_v->next;
	last = ps_lstlast(*stack);
	
	while (min_v && compare)
	{
		if (min_v->content > compare->content)
			min_v = compare;
		else
			compare = compare->next;
	}
	if (min_v->content > last->content)
		min_v = last;
	return (min_v->content);
}

int	check_sorted(t_stack **stack)
{
	int	i;
	
	i = (*stack)->content;
	while (stack)
	{
		if (i > (*stack)->content)
		{
			return (0);
		}
		i = (*stack)->content;
		(*stack) = (*stack)->next; 
	}
	return (1);
}

int	check_rev_sorted(t_stack **stack)
{
	int	i;
	
	i = (*stack)->content;
	while (stack)
	{
		if (i < (*stack)->content)
		{
			return (0);
		}
		i = (*stack)->content;
		(*stack) = (*stack)->next; 
	}
	return (1);
}