/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:24:35 by utente            #+#    #+#             */
/*   Updated: 2024/12/20 17:58:53 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack **stack)
{
    if (!*stack || !(*stack)->next)
        return;

    t_stack *prev = NULL;
    t_stack *current = *stack;

    // Traverse to the last node
    while (current->next) {
        prev = current;
        current = current->next;
    }

    // Adjust pointers to rotate the list
    prev->next = NULL;
    current->next = *stack;
    *stack = current;
}

void	rra(t_stack **a, int checker)
{
	reverse_rotate(a);
	if (checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int checker)
{
	reverse_rotate(b);
	if (checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (checker)
		write(1, "rrr\n", 4);
}
