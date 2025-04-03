/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:57:22 by utente            #+#    #+#             */
/*   Updated: 2025/04/03 15:11:27 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief free the 2d array
 * @param argv array to free
*/
void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

/**
 * @brief free the stack
 * @param stack stack to free
 */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/**
 * @brief free the stack and print error message
 * @param a stack a
*/
void	error_free(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief check if the string is a valid number
 * @param str string to check
 * @return 1 if the string is not a valid number, 0 is a valid number
*/
int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

/**
 * @brief check if the number is same in the stack
 * @param a stack a
 * @param nbr number to check
 * @return 1 if the number is same, 0 if the number is not same
*/
int	error_duplicate(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
