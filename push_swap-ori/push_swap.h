/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:42:44 by utente            #+#    #+#             */
/*   Updated: 2024/01/23 15:03:28 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;	

//*** Handle input ./push_swap "1 -42 1337" ***
char			**ft_split(char *str, char separator);

//*** Handle errors-free ***
void			free_split(char **argv);
void			error_free(t_stack **a);
void			free_stack(t_stack **stack);
int				error_duplicate(t_stack *a, int nbr);
int				error_syntax(char *str);

//*** Stack creation ***
void			stack_init(t_stack **a, char **argv);
void			init_nodes(t_stack *a, t_stack *b);
void			set_current_position(t_stack *stack);
void			set_push_cost(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);

//*** linked list utils ***
void			append_node(t_stack **stack, int nbr);
t_stack			*find_last_node(t_stack *head);
t_stack			*find_smallest(t_stack *stack);
t_stack			*return_cheapest(t_stack *stack);
bool			stack_sorted(t_stack *stack);
int				stack_len(t_stack *stack);
void			finish_rotation(t_stack **s, t_stack *n, char c);

//*** Algorithms ***
void			sort_three(t_stack **a);
void			handle_five(t_stack **a, t_stack **b);
void			sort_stack(t_stack **a, t_stack **b);

//*** Commands ***
void			sa(t_stack **a, bool checker);
void			sb(t_stack **b, bool checker);
void			ss(t_stack **a, t_stack **b, bool checker);
void			ra(t_stack **a, bool checker);
void			rb(t_stack **b, bool checker);
void			rr(t_stack **a, t_stack **b, bool checker);
void			rra(t_stack **a, bool checker);
void			rrb(t_stack **b, bool checker);
void			rrr(t_stack **a, t_stack **b, bool checker);
void			pa(t_stack **a, t_stack **b, bool checker);
void			pb(t_stack **b, t_stack **a, bool checker);

#endif
