/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:53:41 by utente            #+#    #+#             */
/*   Updated: 2024/02/22 10:32:22 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @breif swap operation
 * @param head stack to swap
*/
static void	swap(t_stack **head)
{
	if (*head == NULL || head == NULL) //if the stack pointer is NULL or the node is null
		return ;
	if ((*head)->next == NULL) //if there is only one node
		return ;
	*head = (*head)->next; //move the pointer to the next node
	(*head)->prev->prev = *head; //set the previous node of the previous node to the current node
	(*head)->prev->next = (*head)->next; //set the next node of the previous node to the next node
	if ((*head)->next != NULL) //if there is a next node
		(*head)->next->prev = (*head)->prev; //set the previous node of the next node to the previous node
	(*head)->next = (*head)->prev; //set the next node to the previous node
	(*head)->prev = NULL; //set the previous node to NULL
}

/**
 * @brief swap in stack a
 * @param a stack a
 * @param checker 1 if checker is on, 0 if checker is off
*/
void	sa(t_stack	**a, int checker)
{
	swap(a);
	if (checker == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int checker)
{
	swap(b);
	if (checker == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int checker)
{
	swap(a);
	swap(b);
	if (checker == 1)
		write(1, "ss\n", 3);
}
