/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:16:30 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/28 10:11:51 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*small;

	curr = stack;
	small = curr;
	while (curr)
	{
		if (small->value > curr->value)
			small = curr;
		curr = curr->next;
	}
	return (small);
}

t_stack	*find_bigest(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*big;

	curr = stack;
	big = curr;
	while (curr)
	{
		if (big->value < curr->value)
			big = curr;
		curr = curr->next;
	}
	return (big);
}
