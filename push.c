/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:36:47 by utente            #+#    #+#             */
/*   Updated: 2024/12/20 17:59:22 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **dest, t_stack **src)
{
    t_stack *node_to_push;

    if (!*src)
        return;

    node_to_push = *src;
    *src = (*src)->next;

    if (NULL == *dest)
    {
        *dest = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        *dest = node_to_push;
    }
}

void	pa(t_stack **a, t_stack **b, int checker)
{
	push(a, b);
	if (checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, int checker)
{
	push(b, a);
	if (checker)
		write(1, "pb\n", 3);
}
