/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:47:02 by utente            #+#    #+#             */
/*   Updated: 2024/01/19 13:24:10 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node)
		rr(a, b, false);
	set_current_index(*a);
	set_current_index(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node)
		rrr(a, b, false);
	set_current_index(*a);
	set_current_index(*b);
}

/*
	if either not top mode check belong "a" or "b" to male it top
*/
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

/*
	1. found the cheapest and return
	2. if both is above 
	3. if both is below
	4. if only "b" above make "b" to top
	5. if only "a" above make "a" to top
*/
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

/*
	1. push every node to "b" until left 3 node and sort it to small to big
	2. push to "a" iwth "init_node" and "move_node"
	3. check the current position and check the number is sort from small to big
	4. if not sort it 
*/
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
	set_current_index(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
