/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:23:46 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/26 16:24:11 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_is_mid(t_stack **stack_a, t_stack *big)
{
	if (!big->next)
		sa(stack_a);
	else
		ra(stack_a);
}

void	big_is_mid(t_stack **stack_a, t_stack *small)
{
	if (!small->next)
		rra(stack_a);
	else
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	three(t_stack **stack_a)
{
	t_stack	*curr;
	t_stack	*small;
	t_stack	*big;

	curr = *stack_a;
	small = find_smallest(*stack_a);
	big = find_bigest(*stack_a);
	if (curr->next == small)
		small_is_mid(stack_a, big);
	else if (curr->next == big)
		big_is_mid(stack_a, small);
	else if (!small->next)
	{
		sa(stack_a);
		rra(stack_a);
	}
}
