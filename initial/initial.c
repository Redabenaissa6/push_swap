/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:30:14 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/28 10:07:21 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*initial_sa(char **args)
{
	int		i;
	int		flag;
	t_stack	*stack_a;

	i = 0;
	flag = 0;
	stack_a = NULL;
	while (args[i])
	{
		lstadd_back(&stack_a, lstnew((int)ft_atoiv(args[i], &flag)));
		if (flag == 1)
		{
			free_stack(&stack_a);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->value >= stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*stack = NULL;
}

static void	initial_index(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr)
	{
		curr->index = -1;
		curr = curr->next;
	}
}

void	index_stack(t_stack **stack)
{
	t_stack	*min;
	t_stack	*curr;
	int		i;
	int		size;

	initial_index(stack);
	i = 0;
	size = lstsize(*stack);
	while (i < size)
	{
		curr = *stack;
		min = NULL;
		while (curr)
		{
			if (curr->index == -1 && (!min || min->value > curr->value))
				min = curr;
			curr = curr->next;
		}
		if (min)
			min->index = i++;
	}
}
