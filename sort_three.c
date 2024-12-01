/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:31:22 by utente            #+#    #+#             */
/*   Updated: 2024/02/22 11:09:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief check the stack was sorted or not
 * @param stack the stack to check
 * @return 1 if the stack is sorted, 0 if not sorted
*/
int	stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * @breif find the biggest number in the stack
 * @param stack the stack to check
 * @return the biggest number in the stack
*/
static t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest_node;

	if (stack == NULL)
		return (NULL);
	biggest_node = stack;
	while (stack)
	{
		if (stack->value > biggest_node->value)
		{
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

/**
 * @brief sort the stack with 3 numbers
 * @param a the stack to sort
*/
void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a); //find the biggest node in stack a
	if (*a == biggest_node) //if the biggest node is the first node
		ra(a, 1);
	else if ((*a)->next == biggest_node) //if the biggest node is the second node
		rra(a, 1);
	if ((*a)->value > (*a)->next->value) //if the first node is bigger than the second node
		sa(a, 1);
}

/**
 * @brief sort the stack with 5 numbers
 * @param a the stack to sort
 * @param b the stack to sort
*/
void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3) //check the stack length is more than 3
	{
		set_current_position(*a);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, 1); //push to stack b until has only 3 node
	}
}
