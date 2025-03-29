/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:52:15 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/27 10:15:04 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	revers_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*prev_tail;

	if (!*stack || !(*stack)->next)
		return ;
	head = lstlast(*stack);
	prev_tail = lstbefore_last(*stack);
	prev_tail->next = NULL;
	head->next = *stack;
	*stack = head;
}

void	rra(t_stack **stack_a)
{
	revers_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	revers_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	revers_rotate(&stack_a);
	revers_rotate(&stack_b);
	ft_putendl_fd("rrr", 1);
}
