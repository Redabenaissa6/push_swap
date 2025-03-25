/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-ais <rben-ais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:05:36 by rben-ais          #+#    #+#             */
/*   Updated: 2025/03/25 06:44:58 by rben-ais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    sa(t_stack *stack)
{
    if(!stack || !stack->next)
        return;
    ft_swap(&stack->value, &stack->next->value);
}

void    sb(t_stack *stack)
{
    if(!stack || !stack->next)
        return;
    ft_swap(&stack->value, &stack->next->value);
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void    ra(t_stack **stack_a)
{
    t_stack *head;
    t_stack *tail;
    
    if(!*stack_a || !(*stack_a)->next)
        return;
    head = *stack_a;
    *stack_a = (*stack_a)->next;
    tail = lstlast(*stack_a);
    tail->next = head;
    head->next = NULL;
}

void    rb(t_stack **stack_b)
{
    t_stack *head;
    t_stack *tail;
    
    if(!*stack_b || !(*stack_b)->next)
        return;
    head = *stack_b;
    *stack_b = (*stack_b)->next;
    tail = lstlast(*stack_b);
    tail->next = head;
    head->next = NULL;
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(&stack_a);
    rb(&stack_b);
}

void    rra(t_stack **stack_a)
{
    t_stack *head;
    t_stack *prev_tail;
    
    if(!*stack_a || !(*stack_a)->next)
        return;
    head = lstlast(*stack_a);
    prev_tail = lstbefore_last(*stack_a);
    prev_tail->next = NULL;
    head->next = *stack_a;
    *stack_a = head;
}

void    rrb(t_stack **stack_b)
{
    t_stack *head;
    t_stack *prev_tail;
    
    if(!*stack_b || !(*stack_b)->next)
        return;
    head = lstlast(*stack_b);
    prev_tail = lstbefore_last(*stack_b);
    prev_tail->next = NULL;
    head->next = *stack_b;
    *stack_b = head;
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(&stack_a);
    rrb(&stack_b);
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (!*stack_b)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (!*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
}