/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:25:55 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/18 14:13:12 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(char *nbr)
{
	int	i;
	
	i = 0;
	if (nbr[0] == '+' || nbr[0] == '-')
		i++;
	if (!nbr[i])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i++]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);	
}

int	check_repeat(int numbers, char **args, int i)
{
	while(args[++i])
	{
		if (ft_atoi(args[i]) == numbers)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

int	check_array(char **args, int i)
{
	int	numbers;
	
	while (args[i])
	{
		numbers = ft_atoi(args[i]);
		if (check_numbers(args[i]))
			return (1);
		if (check_repeat(numbers, args, i))
			return (1);
		if (numbers < -2147483648 || numbers > 2147483647)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	char	**args;
	int	i;
	int	valid;
	
	i = 0;
	if(argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	valid = check_array(args, i);
	if (!args[0])
		free_array(args);
	if (argc == 2)
		free_array(args);
	if (valid)
		return (1);
	return (0);
}