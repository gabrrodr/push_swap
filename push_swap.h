/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrrodr <gabrrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:16:46 by gabrrodr          #+#    #+#             */
/*   Updated: 2023/09/12 13:35:58 by gabrrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

int		check_args(int argc, char **argv);
void	init_stack(t_stack **stack, int argc, char **argv);
void	free_array(char **array);
void	free_content(t_stack **a, t_stack **b, t_stack **dupe_pos);
void	free_data(t_stack **stack);
void	free_copy(t_stack *stack);
long	ps_atol(const char *nptr);


//lists
t_stack	*ps_lstnew(int content);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
int		ps_lstsize(t_stack *lst);

int		find_max_value(t_stack **stack);
int		find_min_value(t_stack **stack);

//operations
int		swap(t_stack **stack);
int		push(t_stack **stack1, t_stack **stack2);
int		rotate(t_stack **stack);
int		rev_rotate(t_stack **stack);

void	assign_index(t_stack *sorted);
int		find_index(int n, t_stack *sorted);
t_stack	*copy_stack(t_stack *a);
t_stack	**create_pos(t_stack **a, t_stack **positive);

void	bubble_sort(t_stack *a);

int		check_sorted(t_stack **stack);
int		check_rev_sorted(t_stack **stack);

void	sort(t_stack **a, t_stack **b, t_stack **dupe);
void	print_list(t_stack *lst);
int		ops(t_stack **a, t_stack **b, char *op);
void	quick_sort(t_stack **a, t_stack **b);

#endif