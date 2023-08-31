/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:11:48 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/31 14:37:29 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)//swap first two nodes
{
	char	*tmp;
	
	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->content; 
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
	return (0);
}

int	push(t_stack **stack1, t_stack **stack2)//take the first element at the top of a/b and put it at the top of b/a.
{
	t_stack	*node1;
	t_stack	*node2;
	
	if ((*stack1))
	{
		node1 = (*stack1);
		node2 = ps_lstnew((*stack1)->content);
		if ((*stack2))
			ps_lstadd_front(stack2, node2);
		else
			(*stack2) = node2;
		(*stack1) = (*stack1)->next;
		free(node1);
		return (1);
	}
	return (0);
}

int	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		ps_lstadd_back(stack, tmp);
		tmp->next = NULL;
	}
	return (1);
}

int	rev_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;
	
	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack);
		while (tmp->next->next)
			tmp = tmp->next;
		node = ps_lstlast(*stack);
		ps_lstadd_front(stack, node);
		tmp->next = NULL;
	}
	return (1);
}