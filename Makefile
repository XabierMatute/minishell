# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 18:46:30 by jperez            #+#    #+#              #
#    Updated: 2023/01/30 18:46:33 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

SRC :=	main.c					\
		Utils/ignoreq.c			\
		Parse/validsintax.c		\
		Utils/contain.c			\
		Utils/closed.c			\
		Utils/ft_split.c		\
		Utils/ft_wlen.c			\
		Utils/liberatesl.c		\
		built-ins/ft_pwd.c		\
		built-ins/ft_cd.c		\
		built-ins/ft_echo.c	\
		built-ins/ft_export.c	\
		built-ins/ft_unset.c	\
		Pipes/pipes.c \
		
OBJ := $(SRC:%.c=%.o)

SANI 	:= -fsanitize=address -g3

RLFLAGS := -lreadline -L /Users/xmatute-/.brew/opt/readline/lib -I /Users/xmatute-/.brew/opt/readline/include

CC 		:= gcc
CFLAGS 	:= -Wall  -Wextra  $(SANI) $(RLFLAGS)

# CFLAGS 	:= -Wall -Werror -Wextra $(SANI) $(RLFLAGS)


RM 		:= rm -rf

val 	:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) ft_printf/libftprintf.a libft/libft.a -o $(NAME)

clean :
		$(RM) $(OBJ)
		make clean -C libft
		make clean -C ft_printf

fclean : clean
		make fclean -C libft
		make fclean -C ft_printf
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
