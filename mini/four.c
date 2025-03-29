/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:24:12 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/27 09:49:50 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*small;
	t_stack	*curr;
	int		pos;

	pos = 1;
	curr = *stack_a;
	small = find_smallest(*stack_a);
	while (curr != small)
	{
		curr = curr->next;
		pos++;
	}
	if (pos == 2)
		sa(stack_a);
	else if (pos == 3)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (pos == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	three(stack_a);
	pa(stack_a, stack_b);
}
