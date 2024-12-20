/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:53:41 by utente            #+#    #+#             */
/*   Updated: 2024/12/20 18:19:23 by welow            ###   ########.fr       */
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
