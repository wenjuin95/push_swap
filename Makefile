# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 12:14:59 by utente            #+#    #+#              #
#    Updated: 2024/12/20 18:07:01 by welow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = 	error_free.c push.c reverse_rotate.c rotate.c \
		sort_stack.c sort_three.c stack_init.c stack_utils.c \
		swap.c init_node.c
MAN = push_swap.c
BONUS = checker.c
OBJ_MAN = $(MAN:.c=.o)
OBJ_SRC = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_SRC) $(OBJ_MAN)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_SRC) $(OBJ_MAN) libft.a -o $@

$(NAME2) : $(OBJ_SRC) $(OBJ_BONUS)
	make all -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_SRC) $(OBJ_BONUS) libft.a -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ_MAN)
	rm -f $(OBJ_SRC)
	rm -f $(OBJ_BONUS)
	rm -f libft.a

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME2)
	make fclean -C libft

re : fclean all

bonus: $(NAME2)

.PHONY : all clean fclea re
