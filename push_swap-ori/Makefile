# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welow < welow@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 12:14:59 by utente            #+#    #+#              #
#    Updated: 2024/01/09 16:53:11 by welow            ###   ########.fr        #
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
OBJS = $(SRCS:.c=.o)
OBJM = $(MAN:.c=.o)
OBJB = $(BS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(OBJM)
	$(CC) $(CFLAGS) $(OBJS) $(OBJM) -o $@

$(NAME2) :$(OBJS) $(OBJB)
	$(CC) $(CFLAGS) $(OBJS) $(OBJB) -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean :
	rm -f $(OBJS)
	rm -f $(OBJM)
	rm -f $(OBJB)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME2)

re : fclean all

bonus: $(NAME2)

.PHONY : all clean fclea re
