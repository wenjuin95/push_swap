/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:24:35 by utente            #+#    #+#             */
/*   Updated: 2024/02/22 10:31:53 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !stack)
		return ;
	last_node = find_last_node(*stack);
	if (last_node == *stack)
		return ;
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
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
