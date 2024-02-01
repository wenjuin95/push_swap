/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:44:38 by welow             #+#    #+#             */
/*   Updated: 2024/02/01 16:44:38 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_cmd(t_stack **a, t_stack **b, char *c)
{
	if (!ft_strncmp(c, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(c, "pb\n", 3))
		pb(b, a, true);
	else if (!ft_strncmp(c, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(c, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(c, "rrr\n", 4))
		rrr(a, b, true);
	else if (!ft_strncmp(c, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(c, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(c, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(c, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(c, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(c, "ss\n", 3))
		ss(a, b, true);
	else
		del_error(a, b);
	free(c);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*next_line;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = make_input(argv);
	stack_init(&a, argv, argc);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_cmd(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
}
