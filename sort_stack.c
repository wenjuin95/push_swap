/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:47:02 by utente            #+#    #+#             */
/*   Updated: 2024/02/22 10:59:22 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the loop to check either "a" is the first or "b" is the first
static void	rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node)
		rr(a, b, 1);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node)
		rrr(a, b, 1);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack **s,
							t_stack *top_node,
							char c)
{
	while (*s != top_node)
	{
		if (c == 'a')
		{
			if (top_node->above_median == 1)
				ra(s, 1);
			else
				rra(s, 1);
		}
		else if (c == 'b')
		{
			if (top_node->above_median == 1)
				rb(s, 1);
			else
				rrb(s, 1);
		}
	}
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*c_node;

	c_node = return_cheapest(*b);
	if (c_node->above_median == 1 && c_node->target_node->above_median == 1)
		rotate_both(a, b, c_node);
	else if (c_node->above_median == 0
		&& c_node->target_node->above_median == 0)
		reverse_rotate_both(a, b, c_node);
	finish_rotation(b, c_node, 'b');
	finish_rotation(a, c_node->target_node, 'a');
	pa(a, b, 1);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, 1);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median == 1)
		while (*a != smallest)
			ra(a, 1);
	else
		while (*a != smallest)
			rra(a, 1);
}
