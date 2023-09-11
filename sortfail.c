/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:18:08 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/05 14:09:42 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortfail(t_stack **stack1, t_stack **stack2)
{
	t_stack	*min;
	t_stack	*max;
	
	min = find_min_value(stack1);
	max = find_max_value(stack1);
	if (check_sorted(stack1))
	{
		return ;
	}
	while (!check_sorted(stack1) || (*stack2)->content)
	{
		while (ps_lstsize(*stack1) == 3)
		{
			if ((ps_lstlast(*stack1))->content == max)
			{
				swap(stack1);
				ft_printf("sa\n");
				return ;
			}
			if (check_rev_sorted(stack1))
			{
				rotate(stack1);
				ft_printf("ra\n");
			}
			if ((*stack1)->content == max)
			{
				rotate(stack1);
				ft_printf("ra\n");
				return ;
			}
			if ((ps_lstlast(*stack1))->content == min)
			{
				rotate(stack1);
				ft_printf("ra\n");
			}
			if ((*stack1)->content == min)
			{
				rotate(stack1);
				ft_printf("ra\n");
			}
		}
		if (check_rev_sorted(stack1) && !(*stack2)->content)
		{
			while ((*stack1))
			{
				push(stack1, stack2);			
				ft_printf("pb\n");
			}
			while ((*stack2))
			{
				rev_rotate(stack2);
				ft_printf("rrb\n");
				push(stack2, stack1);
				ft_printf("pa\n");
			}
		}
		if ((*stack1)->content == find_min_value(stack1) && !check_sorted(stack1))
		{
			rotate(stack1);
			ft_printf("ra\n");
		}
		if ((*stack1)->content == find_max_value(stack1))
		{
			push(stack1, stack2);
			ft_printf("pb\n");
		}
		if ((*stack1)->content > (*stack1)->next->content)
		{
			push(stack1, stack2);
			ft_printf("pb\n");
			if ((*stack2) && (*stack2)->next && ((*stack2)->content < (*stack2)->next->content))
			{
				rotate(stack2);
				ft_printf("rb\n");
			}
		}
		if (((*stack1)->content < (*stack1)->next->content) && !check_sorted(stack1))
		{
			if ((*stack2) && (*stack2)->next && ((*stack2)->content < (*stack2)->next->content))
			{
				rotate(stack1);
				rotate(stack2);
				ft_printf("rr\n");
			}
			else
			{
				rotate(stack1);
				ft_printf("ra\n");
			}
		}
		if ((*stack2) && (*stack2)->next && ((*stack2)->content > (*stack2)->next->content))
		{
			if (check_rev_sorted(stack2) && check_sorted(stack1))
			{
				while ((*stack2))
				{
					push(stack2, stack1);
					ft_printf("pa\n");
				}
				while ((*stack1) != min)
				{
					rotate(stack1);
					ft_printf("ra\n");
				}
			}
			else
			{
				rotate (stack2);
				ft_printf("rb\n");
			}
		}
		if ((*stack1)->content == min && ps_lstsize(*stack1) == 2)
		{
			rotate(stack1);
			ft_printf("ra\n");
			push(stack1, stack2);
			ft_printf("pb\n");
		}
		if ((*stack2) && (*stack2)->next && ((*stack2)->content < (*stack2)->next->content))
		{
			while ((*stack2) && ((*stack2)->content != find_min_value(stack2)))
			{
				swap(stack2);
				ft_printf("sb\n");
				rotate(stack2);
				ft_printf("rb\n");
			}
		}
		if ((*stack2) && ((*stack2)->content == find_min_value(stack2)) && check_sorted(stack1))
		{
			push(stack2, stack1);
			ft_printf("pa\n");
		}
	}
}