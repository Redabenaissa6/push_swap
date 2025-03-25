/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:38:26 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/25 17:42:31 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int main(int arc, char **arv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *tmp_a;
    t_stack *tmp_b;
    char    **splited;
    
    stack_b = NULL;
    if (arc < 2)
        return(1);
    splited = args(arc, arv);
    if (!splited)
        return (1);
    stack_a = initial_sa(splited);
    if(!is_sorted(stack_a))
        return (free_stack(&stack_a),1);
    
    tmp_a = stack_a;
    tmp_b = stack_b;
    printf("s_a|s_b\n");
    while(tmp_a || tmp_b)
    {
        if(tmp_a)
        {
            printf("%d",tmp_a->value);
            tmp_a = tmp_a->next;
        }
        else
            printf(" ");
        
        printf("|");
        if(tmp_b)
        {
            printf("%d",tmp_b->value);
            tmp_b = tmp_b->next;
        }
        else
            printf(" ");
        if(tmp_b || tmp_a)
            printf("\n");
    }
}
