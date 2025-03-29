/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:38:06 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/28 07:09:01 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

char	**args(int arc, char **arv);
void	free_matrix(char **str);
int		only_space(char **arv);
int		only_zeros(char *number, int *i);
int		duplicate(t_stack *stack_a);
int		ft_atoiv(const char *str, int *flag);
int		is_sorted(t_stack *stack_a);
int		lstsize(t_stack *lst);
void	ft_swap(int *a, int *b);
void	lstadd_back(t_stack **lst, t_stack *new);
void	free_stack(t_stack **stack);
void	index_stack(t_stack **stack);
void	three(t_stack **stack_a);
void	four(t_stack **stack_a, t_stack **stack_b);
void	five(t_stack **stack_a, t_stack **stack_b);
void	handle_stack(t_stack **stack_a, t_stack **stack_b);

void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

t_stack	*lstbefore_last(t_stack *lst);
t_stack	*lstnew(int value);
t_stack	*initial_sa(char **args);
t_stack	*lstlast(t_stack *lst);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_bigest(t_stack *stack);

#endif