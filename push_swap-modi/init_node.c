/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:02:48 by utente            #+#    #+#             */
/*   Updated: 2024/01/17 12:22:18 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	this to get thier position and check whether is above or below median
*/
void	set_current_position(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= center)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

/*
	first if is for "b" to look for a
	second if can't find then look for the smallest node to target
*/
static void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int		match_index;

	while (b)
	{
		match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < match_index)
			{
				match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == INT_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*
	first if to check b is not above median(if is will skip)
	second if is to check b target_node is above median
*/
void	set_push_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

/*
	loop through and compare which is the cheapest
*/
void	set_cheapest(t_stack *b)
{
	int		match_value;
	t_stack	*match_node;

	if (! b)
		return ;
	match_value = INT_MAX;
	while (b)
	{
		if (b->push_cost < match_value)
		{
			match_value = b->push_cost;
			match_node = b;
		}
		b = b->next;
	}
	match_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_push_cost(a, b);
	set_cheapest(b);
}
