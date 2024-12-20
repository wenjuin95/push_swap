/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:07:07 by utente            #+#    #+#             */
/*   Updated: 2024/12/20 18:00:12 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    if (!*stack || !(*stack)->next)
        return;

    t_stack *first_node = *stack;
    t_stack *last_node = *stack;

    last_node = find_last_node(last_node);

    // Adjust pointers to rotate the list
    *stack = first_node->next;
    first_node->next = NULL;
    last_node->next = first_node;
}

void	ra(t_stack **a, int checker)
{
	rotate(a);
	if (checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int checker)
{
	rotate(b);
	if (checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int checker)
{
	rotate(a);
	rotate(b);
	if (checker)
		write(1, "rr\n", 3);
}
