# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:33:39 by xmatute-          #+#    #+#              #
#    Updated: 2023/01/19 18:23:48 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

SRC :=	main.c  \
		Utils/ignoreq.c	\
		Parse/validsintax.c \
		Utils/contain.c	\
		Utils/closed.c	\

		
OBJ := $(SRC:%.c=%.o)

SANI 	:= -fsanitize=address -g3

CC 		:= gcc
# CFLAGS 	:= -Wall  -Wextra -Werror $(SANI)
# CFLAGS 	:= -Wall -Werror -Wextra $(SANI)

RM 		:= rm -rf

val 	:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


all : $(NAME)

$(NAME) : $(OBJ)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) ft_printf/libftprintf.a -o $(NAME)

clean :
		$(RM) $(OBJ)
		make clean -C ft_printf

fclean : clean
		make fclean -C ft_printf
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re