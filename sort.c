/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:11:07 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/07 15:59:57 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bits(t_stack **dupe_positive)
{
	t_stack	*head;
	int	max;
	int	i;
	
	head = (*dupe_positive);
	max = head->content;
	while (head)
	{
		if (head->content > max)
		{
			max = head->content;
		}
		head = head->next;
	}
	i = 0;
	while ((max >> i) != 0)
	{
		i++;
	}
	return (i);
}

void	radix_sort(t_stack **dupe_positive, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;
	
	i = 0;
	size = ps_lstsize((*dupe_positive));
	max_bits = get_bits(dupe_positive);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*dupe_positive)->content >> i) & 1) == 1)
				ops(dupe_positive, NULL, "ra");
			else
				ops(dupe_positive, b, "pb");
			j++;
		}
		while (ps_lstsize(*b))
			ops(dupe_positive, b, "pa");
		i++;
	}
}

void	sort(t_stack **a, t_stack **b, t_stack **dupe)
{
	if (ps_lstsize(*a) <= 5)
		quick_sort(a, b);
	if (ps_lstsize(*a) > 5)
		radix_sort(dupe, b);
}