/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:46:14 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/07 10:56:57 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	t_stack	*node;

	node = (*stack);
	if (node && node->next)
	{
		if ((int)(long)node->content > (int)(long)node->next->content)
			ops(stack, NULL,"sa");
	}
}

void	sort_3(t_stack **stack)
{
	int	min;
	int	max;
	
	min = find_min_value(stack);
	max = find_max_value(stack);
	while (!check_sorted(stack))
	{
		if ((int)(long)(ps_lstlast(*stack))->content == (int)(long)max)
			ops(stack, NULL, "sa");
		if (check_rev_sorted(stack))
			ops(stack, NULL, "ra");
		if ((int)(long)(*stack)->content == (int)(long)max)
			ops(stack, NULL, "ra");
		if ((int)(long)(ps_lstlast(*stack))->content == (int)(long)min)	
			ops(stack, NULL, "ra");
		if (!check_sorted(stack) && (int)(long)(*stack)->content == (int)(long)min)
			ops(stack, NULL, "rra");
	}
}

void	send_min(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min_value(a);
	while ((int)(long)(*a)->content != (int)(long)min)
	{
		if ((int)(long)(*a)->next->content != (int)(long)min)
			ops(a, b, "rra");
		else
			ops(a, b, "ra");
	}
	ops(a, b, "pb");
}

void	sort_4_5(t_stack **a, t_stack **b)
{
	if (ps_lstsize(*a) == 5)
		send_min(a, b);
	send_min(a, b);
	sort_3(a);
	if (ps_lstsize(*b) == 2)
		ops(a, b, "pa");
	ops(a, b, "pa");
}

void	quick_sort(t_stack **a, t_stack **b)
{
	if (check_sorted(a))
		return ;
	if (ps_lstsize(*a) == 2)
		sort_2(a);
	if (ps_lstsize(*a) == 3)
		sort_3(a);
	if (ps_lstsize(*a) == 4 || ps_lstsize(*a) == 5)
		sort_4_5(a, b);
}
