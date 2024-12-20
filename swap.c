/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:53:41 by utente            #+#    #+#             */
/*   Updated: 2024/12/20 17:57:42 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **head)
{
    if (!*head || !(*head)->next)
        return;

    t_stack *first = *head;
    t_stack *second = (*head)->next;

    first->next = second->next;
    second->next = first;
    *head = second;
}

void	sa(t_stack	**a, int checker)
{
	swap(a);
	if (checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int checker)
{
	swap(b);
	if (checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int checker)
{
	swap(a);
	swap(b);
	if (checker)
		write(1, "ss\n", 3);
}
