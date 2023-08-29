/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:18:08 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/29 19:40:06 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack1, t_stack **stack2)
{
	t_stack	*min;
	t_stack	*max;
	
	min = find_min_value(stack1);
	max = find_max_value(stack1);
	if (check_sorted(stack1))
	{
		ft_printf("its organised");
		return ;
	}
	while (ps_lstsize(stack1) == 3 && !check_sorted(stack1))
	{
		if ((ps_lstlast(*stack1))->content == max)
		{
			swap(stack1);
			ft_printf("sa");
			return ;
		}
		if (check_rev_sorted(stack1))
		{
			rotate(stack1);
			ft_printf("ra");
		}
		if ((*stack1)->content == max)
		{
			rotate(stack1);
			ft_printf("ra");
			return ;
		}
		if ((ps_lstlast(*stack1))->content == min)
		{
			rotate(stack1);
			ft_printf("ra");
		}
	}
	if (check_rev_sorted(stack1))
	{
		while (stack1)
		{
			push(stack1, stack2);
			ft_printf("pb");
		}
		while (stack2 && ((*stack2)->content != max))
		{
			rotate(stack2);
			ft_printf("rb");
		}
		rotate(stack2);
		ft_printf("rb");
		while (stack2)
		{
			push(stack2, stack1);
			ft_printf("pa");
		}
	}
	if ((*stack1)->content == min && !check_sorted(stack1))
	{
		rotate(stack1);
		ft_printf("ra");
	}
	if ((*stack1)->content == max)
	{
		push(stack1, stack2);
		ft_printf("pb");
	}
	if ((*stack1)->content > (*stack1)->next->content)
	{
		push(stack1, stack2);
		ft_printf("pb");
	}
	if (((*stack1)->content < (*stack1)->next->content) && !check_sorted(stack1))
	{
		if ((*stack2) && (*stack2)->next && ((*stack2)->content < (*stack2)->next->content))
		{
			rotate(stack1);
			rotate(stack1);
			ft_printf("rr");
		}
		else
		{
			rotate(stack1);
			ft_printf("ra");
		}
	}
	if (ps_lstsize(*stack2) > 2 && ((*stack2)->content < (*stack2)->next->content))
	{
		(*stack2) = (*stack2)->next->next; 
		if (check_rev_sorted(*stack2))
		{
			(*stack2) = (*stack2)->prev->prev;
			swap(stack2);
			ft_printf("sb");
			rotate (stack2);
			ft_printf("rb");
		}
	}
	if ((*stack2) && (*stack2)->next)
	{
		if ((*stack2)->content < (*stack2)->next->content)
		{
			rotate(stack2);
			ft_printf("rb");
		}
		if (check_rev_sorted(stack2) && check_sorted(stack1))
		{
			while (stack2)
			{
				push(stack2, stack1);
				ft_printf("pa");
			}
			while ((*stack1) != min)
			{
				rotate(stack1);
				ft_printf("ra");
			}
			return ;
		}
	}
}