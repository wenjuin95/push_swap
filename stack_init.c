/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:42:38 by utente            #+#    #+#             */
/*   Updated: 2024/02/01 22:32:50 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief similar to atoi but for long
 * @param str string to convert
 * @return converted number
*/
long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/**
 * @brief join all argument into a single string and split it into an array
 * @param argv argument vector
 * @return array of strings
*/
char	**make_input(char **argv)
{
	char	*str;
	char	*s1;
	char	*s2;
	int		i;
	char	**argument;

	i = 0;
	str = ft_strdup("");
	while (argv[i])
	{
		s1 = ft_strjoin(str, argv[i]);
		free(str);
		s2 = ft_strjoin(s1, " ");
		str = ft_strdup(s2);
		free(s1);
		free(s2);
		i++;
	}
	argument = ft_split(str, ' ');
	free(str);
	return (argument);
}

/**
 * @brief check and initialize the stack
 * @param a stack a
 * @param argv argument vector
 * @param argc argument count
 * @note 1. check for syntax error
 * @note 2. check for duplicate
 * @note 3. check number range
 * @note 4. "append_node" to add the node to the stack
 * @note 5. free the split array if only 1 number is given
*/
void	stack_init(t_stack **a, char **argv, int argc)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (error_syntax(argv[i]))
			error_free(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a);
		if (error_duplicate(*a, (int)nbr))
			error_free(a);
		append_node(a, (int)nbr);
	}
	if (argc == 2)
		free_split(argv);
}
