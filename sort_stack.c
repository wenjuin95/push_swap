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

/**
 * @brief rotate_both node in stack a and stack b
 * @param a stack a
 * @param b stack b
 * @param c_node the node to rotate
*/
static void	rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node) //if "a" is not a target node and "b" is not the node to rotate
		rr(a, b, 1);
	set_current_position(*a); //after rotating, set the current position of stack a
	set_current_position(*b); //after rotating, set the current position of stack b
}

/**
 * @brief reverse_rotate_both node in stack a and stack b
 * @param a stack a
 * @param b stack b
 * @param c_node the node to reverse rotate
*/
static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *c_node)
{
	while (*a != c_node->target_node && *b != c_node) //if "a" is not a target node and "b" is not the node to rotate
		rrr(a, b, 1);
	set_current_position(*a); //after rotating, set the current position of stack a
	set_current_position(*b); //after rotating, set the current position of stack b
}

/**
 * @brief rotate the cheapest node to the top
 * @param s stack to rotate
 * @param top_node cheapest node
 * @param c which stack
*/
void	finish_rotation(t_stack **s,
							t_stack *top_node,
							char c)
{
	while (*s != top_node) // find the cheapest node
	{
		if (c == 'a') //if the stack is a
		{
			if (top_node->above_median == 1) //if is a cheapest node
				ra(s, 1);
			else //if is not a cheapest node
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

/**
 * @brief move nodes from stack b to stack a
 * @param a stack a
 * @param b stack b
*/
static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*c_node;

	c_node = return_cheapest(*b); //find the cheapest node
	if (c_node->above_median == 1 && c_node->target_node->above_median == 1) //if the cheapest node is above the median and the target node is above the median
		rotate_both(a, b, c_node);
	else if (c_node->above_median == 0
		&& c_node->target_node->above_median == 0) //if the cheapest node is below the median and the target node is below the median
		reverse_rotate_both(a, b, c_node);
	finish_rotation(b, c_node, 'b'); //finish rotating the cheapest node in stack b
	finish_rotation(a, c_node->target_node, 'a');  //finish rotating the target node in stack a
	pa(a, b, 1); //push the cheapest node to stack a
}

/**
 * @brief sort the stack
 * @param a stack a
 * @param b stack b
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*a);
	if (len_a == 5) //if the stack has 5 elements
		handle_five(a, b);
	else //if more than 5 elements
	{
		while (len_a-- > 3)
			pb(b, a, 1); //push all the elements to stack b and left 3 elements in stack a
	}
	sort_three(a); //sort the first 3 elements
	while (*b)
	{
		init_nodes(*a, *b); //initialize the nodes
		move_nodes(a, b); //do the sorting
	}
	set_current_position(*a); //set the current position of stack a
	smallest = find_smallest(*a); //find the smallest node in stack a
	if (smallest->above_median == 1) //if the smallest node is above the median
		while (*a != smallest) //rotate the stack until the smallest node is on top
			ra(a, 1);
	else //if the smallest node is below the median
		while (*a != smallest) //reverse rotate the stack until the smallest node is on top
			rra(a, 1);
}
