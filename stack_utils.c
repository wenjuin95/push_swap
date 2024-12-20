/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:49:59 by utente            #+#    #+#             */
/*   Updated: 2024/12/20 18:03:43 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void append_node(t_stack **stack, int nbr)
{
    t_stack *node;
    t_stack *last_node;

    if (!stack)
        return;
    node = malloc(sizeof(t_stack));
    if (!node)
        return;
    node->next = NULL;
    node->value = nbr;
    if (*stack == NULL)
    {
        *stack = node;
    }
    else
    {
        last_node = *stack;
        while (last_node->next)
        {
            last_node = last_node->next;
        }
        last_node->next = node;
    }
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest_node = stack;
	while (stack)
	{
		if (stack->value < smallest_node->value)
		{
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
