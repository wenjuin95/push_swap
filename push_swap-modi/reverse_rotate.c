/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:24:35 by utente            #+#    #+#             */
/*   Updated: 2024/01/23 16:25:56 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !stack)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
