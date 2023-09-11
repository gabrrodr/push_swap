/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:00:57 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/07 17:57:22 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**create_pos(t_stack **a, t_stack **positive)
{
	t_stack	*copy;
	t_stack	*new_node;
	t_stack	*node;

	node = (*a);
	new_node = NULL;
	copy = copy_stack((*a));
	bubble_sort(copy);
	assign_index(copy);
	while (node)
	{
		new_node = ps_lstnew(find_index(node->content, copy));
		ps_lstadd_back(positive, new_node);
		node = node->next;
	}
	free_copy(copy);
	return (positive);
}

t_stack	*copy_stack(t_stack *a)
{
	t_stack	*new_node;
	t_stack	*dupe;

	dupe = NULL;
	while (a)
	{
		new_node = ps_lstnew(a->content);
		if (!new_node)
			return (NULL);
		ps_lstadd_back(&dupe, new_node);
		a = a->next;
	}
	return (dupe);
}

void	print_list(t_stack *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack **b;
	t_stack	**dupe_pos;
	
	if (argc < 2)
		return (1);
	if(check_args(argc, argv))
		return (1);
	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	dupe_pos = malloc(sizeof(t_stack *));
	if (!a || !b || !dupe_pos)
	{
		free_content(a, b, dupe_pos);
		return (1);
	}
	(*a) = NULL;
	(*b) = NULL;
	(*dupe_pos) = NULL;
	init_stack(a, argc, argv);
	assign_index(*a);
	dupe_pos = create_pos(a, dupe_pos);
	sort(a, b, dupe_pos);
	free_content(a, b, dupe_pos);
}