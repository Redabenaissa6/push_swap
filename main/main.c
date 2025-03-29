/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:38:26 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/28 10:11:55 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int arc, char **arv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splited;

	stack_b = NULL;
	if (arc < 2 || (arc == 2 && !arv[1][0]))
		return (0);
	splited = args(arc, arv);
	if (!splited)
		return (2);
	stack_a = initial_sa(splited);
	if (!stack_a)
		return (2);
	if (!is_sorted(stack_a) || duplicate(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	handle_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
