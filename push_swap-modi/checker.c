/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:48:34 by welow             #+#    #+#             */
/*   Updated: 2024/01/09 16:48:34 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	del_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_cmd(t_stack **a, t_stack **b, char *c)
{
	if (!ft_strcmp(c, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(c, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(c, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(c, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(c, "rrr\n"))
		rrr(a, b, true);
	else if (!ft_strcmp(c, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(c, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(c, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(c, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(c, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(c, "ss\n"))
		ss(a, b, true);
	else
		del_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*next_line;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = make_input(argv);
	stack_init(&a, argv, argc);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_cmd(&a, &b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}
