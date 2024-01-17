/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:47:02 by utente            #+#    #+#             */
/*   Updated: 2024/01/17 12:55:01 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node)
		rrr(a, b, false);
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
			if (top_node->above_median)
				ra(s, false);
			else
				rra(s, false);
		}
		else if (c == 'b')
		{
			if (top_node->above_median)
				rb(s, false);
			else
				rrb(s, false);
		}
	}
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*c_node;

	c_node = return_cheapest(*b);
	if (c_node->above_median && c_node->target_node->above_median)
		rotate_both(a, b, c_node);
	else if (!(c_node->above_median) && !(c_node->target_node->above_median))
		reverse_rotate_both(a, b, c_node);
	finish_rotation(b, c_node, 'b');
	finish_rotation(a, c_node->target_node, 'a');
	pa(a, b, false);
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
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
