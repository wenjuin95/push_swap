/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:42:38 by utente            #+#    #+#             */
/*   Updated: 2024/01/30 13:13:33 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_init(t_stack **a, char **argv, int argc)
{
	long	nbr;
	int		i;

	i = 0;
	if (argc == 2)
		free_split(argv);
	else
	{
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
	}
}
