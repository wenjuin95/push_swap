/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:49:59 by utente            #+#    #+#             */
/*   Updated: 2024/12/20 18:19:10 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief find the last node of the stack
 * @param head head pointer of the stack
 * @return the last node of the stack
*/
t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
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

/**
 * @brief find the smallest node in the stack
 * @param stack stack to search
 * @return the smallest node in the stack
*/
t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest_node = stack;
	while (stack)
	{
		if (stack->value < smallest_node->value) //if the current node is smaller than the smallest node
			smallest_node = stack; //set the current node as the smallest node
		stack = stack->next;
	}
	return (smallest_node);
}

/**
 * @brief find the cheapest node in the stack
 * @param stack stack to search
 * @return the cheapest node in the stack
 */
t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1) //if the node has the "cheapest" flag
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/**
 * @brief get the length of the stack
 * @param stack stack to count
 * @return the length of the stack
*/
int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
