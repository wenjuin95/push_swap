/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:31:22 by utente            #+#    #+#             */
/*   Updated: 2024/01/23 16:20:11 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack	*find_biggest(t_stack *stack)
{
	int				big;
	t_stack			*biggest_node;

	if (!stack)
		return (NULL);
	big = INT_MIN;
	while (stack)
	{
		if (stack->value > big)
		{
			big = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a == biggest_node)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		set_current_position(*a);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
