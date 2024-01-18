/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:02:48 by utente            #+#    #+#             */
/*   Updated: 2024/01/18 12:39:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	this to get thier position and check whether is above or below median
*/
void	set_current_index(t_stack *stack)
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
	1. if is for "b" to look for "a" nearest and biggest number to target
	example: 
			6 > 3 && 6 < INT_MAX (6 will be the match_index)
			5 > 3 && 5 < 6       (update 6 to 5)
	2. if can't find then look for the smallest number to target
	note: when same number in < or > is false
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
	note: when same number in < or > is false
*/
void	set_cheapest(t_stack *b)
{
	int		match_value;
	t_stack	*match_node;

	if (!b)
		return ;
	match_value = b->value;
	match_node = b;
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
	set_current_index(a);
	set_current_index(b);
	set_target_node(a, b);
	set_push_cost(a, b);
	set_cheapest(b);
}
