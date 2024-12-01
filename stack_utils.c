/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:49:59 by utente            #+#    #+#             */
/*   Updated: 2024/02/22 11:08:03 by welow            ###   ########.fr       */
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

/**
 * @brief assing number to node and append it to the stack
 * @param stack stack to append the node
 * @param nbr number to assign to the node
*/
void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL) //if the stack is empty
	{
		*stack = node; //append the node to the stack
		node->prev = NULL; //set the previous node to NULL
	}
	else //if the stack is not null 
	{
		last_node = find_last_node(*stack); //find the last node
		last_node->next = node; //the last node will append the new node
		node->prev = last_node; //the new node will point to the last node
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
