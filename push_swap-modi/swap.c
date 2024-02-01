/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:53:41 by utente            #+#    #+#             */
/*   Updated: 2024/02/01 16:58:22 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	if (!*head || !head)
		return ;
	if (!(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
