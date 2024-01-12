/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:48:08 by welow             #+#    #+#             */
/*   Updated: 2024/01/09 15:48:08 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"

void	parse_cmd(t_stack **a, t_stack **b, char *c);
void	del_error(t_stack **a, t_stack **b);
int		ft_strcmp(char *s1, char *s2);

#endif