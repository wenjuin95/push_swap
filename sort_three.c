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

static t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest_node;

	if (!stack)
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

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest(*a);
	if (*a == biggest_node)
		ra(a, 1);
	else if ((*a)->next == biggest_node)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		set_current_position(*a);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, 1);
	}
}
