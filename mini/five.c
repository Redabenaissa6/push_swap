/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:24:17 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/27 09:48:59 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_to_top(t_stack **stack_a, int pos)
{
	if (pos == 2)
		sa(stack_a);
	else if (pos == 3)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (pos == 4)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (pos == 5)
		rra(stack_a);
}

void	five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*small;
	t_stack	*curr;
	int		pos;

	curr = *stack_a;
	small = find_smallest(*stack_a);
	pos = 1;
	while (curr != small)
	{
		curr = curr->next;
		pos++;
	}
	push_to_top(stack_a, pos);
	pb(stack_a, stack_b);
	four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
