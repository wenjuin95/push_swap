/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:02:48 by utente            #+#    #+#             */
/*   Updated: 2024/02/22 11:00:50 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief set the current position for each node and check whether is above or below median
 * @param stack the node to set the position
*/
void	set_current_position(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = stack_len(stack) / 2; //get the middle of the stack
	while (stack)
	{
		stack->index = i;
		if (i <= center) //if the index is less than the middle
			stack->above_median = 1; //set above median to 1
		else
			stack->above_median = 0; //set below median to 0
		stack = stack->next;
		++i;
	}
}

/**
 * @brief set the target node for each node in stack b
 * @param a the stack a
 * @param b the stack b
*/
static void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	int		match_index;

	while (b)
	{
		match_index = INT_MAX; //assign max value
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < match_index) //if the value is greater than b and less than match_index
			{
				match_index = current_a->value; //assign the value to match_index
				target_node = current_a; //assign the node to target_node
			}
			current_a = current_a->next;
		}
		if (match_index == INT_MAX) //if match_index is still max value
			b->target_node = find_smallest(a); //assign the smallest node to target_node
		else //if match_index is not max value
			b->target_node = target_node; //assign the target_node to target_node
		b = b->next;
	}
}

/**
 * @brief set the push cost for each node in stack b
 * @param a the stack a
 * @param b the stack b
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
		if (b->above_median == 0) //if b node is not above median
			b->push_cost = len_b - (b->index); //assign the push cost to the length of b minus the index
		if (b->target_node->above_median == 1) //if the target node is above median
			b->push_cost += b->target_node->index; //add the index of the target node to the push cost
		else //if the target node is not above median
			b->push_cost += len_a - (b->target_node->index); //add the length of a minus the index of the target node to the push cost
		b = b->next;
	}
}

/**
 * @brief find the cheapest node in stack b
 * @param b the stack b
*/
void	set_cheapest(t_stack *b)
{
	int		match_value;
	t_stack	*match_node;

	if (b == NULL)
		return ;
	match_value = INT_MAX;
	while (b)
	{
		if (b->push_cost < match_value) //if the push cost is less than the match value
		{
			match_value = b->push_cost; //assign the push cost to the match value
			match_node = b; //assign the node to the match node
		}
		b = b->next;
	}
	match_node->cheapest = 1; //assign the cheapest node to 1 meaning it is the cheapest node
}

/**
 * @brief initialize the nodes
 * @param a the stack a
 * @param b the stack b
*/
void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_push_cost(a, b);
	set_cheapest(b);
}
