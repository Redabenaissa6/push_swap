/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:30:14 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/25 04:58:23 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *initial_sa(char **args)
{
    int     i;
    t_stack *stack_a;
    
    i = 0;
    stack_a = NULL;
    while(args[i])
    {
        lstadd_back(&stack_a, lstnew((int)ft_atoi(args[i])));
        i++;
    }
    return (stack_a);
}
int is_sorted(t_stack *stack_a)
{
    while(stack_a->next)
    {
        if(stack_a->value >= stack_a->next->value)
            return (1);
        stack_a = stack_a->next;
    }
    return (0);
}