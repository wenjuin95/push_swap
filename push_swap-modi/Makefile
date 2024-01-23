# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 12:14:59 by utente            #+#    #+#              #
#    Updated: 2024/01/23 15:44:17 by welow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = 	error_free.c push.c reverse_rotate.c rotate.c \
		sort_stack.c sort_three.c split.c stack_init.c stack_utils.c \
		swap.c init_node.c
MAN = push_swap.c
BS = checker.c get_next_line.c get_next_line_utils.c

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) $(MAN) -o $@

$(NAME2) :
	$(CC) $(CFLAGS) $(SRCS) $(BS) -o $@

	
clean :
	rm -f $(NAME)
	rm -f $(NAME2)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME2)

re : fclean all

bonus: $(NAME2)

.PHONY : all clean fclea re