/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:16:46 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/08/28 17:00:34 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	void			*content;      
	struct s_stack  *next;
	struct s_stack  *prev;
}				t_stack;


int	check_args(int argc, char **argv);
void	init_stack(t_stack **stack, int argc, char **argv);
void    free_array(char **array);
void	free_content(t_stack **a, t_stack **b);


//lists
t_stack	*ps_lstnew(void *content);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
int	ps_lstsize(t_list *lst);


void	*find_max_value(t_stack **stack);
void	*find_min_value(t_stack **stack);

//operations
int	swap(t_stack **stack);
int	push(t_stack **stack1, t_stack **stack2);
int	rotate(t_stack **stack);
int	rev_rotate(t_stack **stack);




# endif