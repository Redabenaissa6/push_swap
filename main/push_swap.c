/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:32:33 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/28 10:11:59 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	pushing(t_stack **stack_a, t_stack **stack_b)
{
	int		a;
	int		b;
	t_stack	*curr;

	a = 0;
	b = (lstsize(*stack_a)) * 0.05 + 10;
	while (*stack_a)
	{
		curr = *stack_a;
		if (curr->index >= a && curr->index <= b)
		{
			pb(stack_a, stack_b);
			a++;
			b++;
		}
		else if (curr->index < a)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			a++;
			b++;
		}
		else if (curr->index > b)
			ra(stack_a);
	}
}

static void	back_to_a(t_stack **stack_b, t_stack *big)
{
	int		size;
	int		pos;
	t_stack	*curr;

	pos = 0;
	size = lstsize(*stack_b);
	curr = *stack_b;
	while (curr && curr != big)
	{
		curr = curr->next;
		pos++;
	}
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(stack_b);
	}
	else
	{
		while (pos++ < size)
			rrb(stack_b);
	}
}

static void	range(t_stack **stack_a, t_stack **stack_b)
{
	index_stack(stack_a);
	pushing(stack_a, stack_b);
	while (*stack_b)
	{
		back_to_a(stack_b, find_bigest(*stack_b));
		pa(stack_a, stack_b);
	}
}

void	handle_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (lstsize(*stack_a) == 1)
		return ;
	else if (lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (lstsize(*stack_a) == 3)
		three(stack_a);
	else if (lstsize(*stack_a) == 4)
		four(stack_a, stack_b);
	else if (lstsize(*stack_a) == 5)
		five(stack_a, stack_b);
	else
		range(stack_a, stack_b);
	return ;
}
