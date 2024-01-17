/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:31:22 by utente            #+#    #+#             */
/*   Updated: 2024/01/17 12:41:58 by welow            ###   ########.fr       */
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

/*
	look for the biggest node
*/
static t_stack	*find_biggest(t_stack *stack)
{
	int		big;
	t_stack	*biggest_node;

	if (NULL == stack)
		return (NULL);
	big = stack->value;
	biggest_node = stack;
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

/*
	1. if the first is biggest then [ra] if second is biggest 
	   then [rra] the third from bottom to top
	2. if the first bigger then second then [sa]
*/
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

/*
	1. first "init_node" of the "set_current_index" to get the 
	   smallest node to top
	2. push every smallest node to "b"
	3. use "init_node" to get everything to [pa] back
*/
void	handle_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		set_current_index(*a);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}
