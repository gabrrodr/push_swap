/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:00:57 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/31 16:30:23 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	
	if (argc < 2)
		return (1);
	if(check_args(argc, argv))
		return (1);
	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	if (!a || !b)
	{
		free_content(a, b);
		return (1);
	}
	init_stack(a, argc, argv);
	//ft_printf("%d\n", find_max_value(a));
	//ft_printf("%d\n", find_min_value(a));
	//push(a, b);
	sort(a, b);
	//print_list(*b);
}