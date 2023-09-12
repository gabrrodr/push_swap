/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:51:13 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/11 10:57:45 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack, int argc, char **argv)
{
	char	**args;
	t_stack	*node;
	int		i;

	i = 0;
	node = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		node = ps_lstnew((long)ft_atoi(args[i++]));
		ps_lstadd_back(stack, node);
	}
	if (argc == 2)
		free_array(args);
}
