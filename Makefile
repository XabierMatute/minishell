# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:33:39 by xmatute-          #+#    #+#              #
#    Updated: 2023/02/08 17:21:23 by jperez           ###   ########.fr        #
#    Updated: 2023/02/01 18:38:30 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

SRC :=	main.c					\
		Utils/ignoreq.c			\
		Parse/validsintax.c		\
		Parse/checknoin.c		\
		Parse/checkpipes.c		\
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
		built-ins/ft_env.c	\
		Utils/ft_args_lenght.c		\
		built-ins/ft_manage_nodes.c	\
		built-ins/ft_manage_stack.c	\
		built-ins/ft_copy_env.c	\
		built-ins/ft_exit.c	\
		signals/ft_signals.c		\
		Pipes/ft_find_cmd.c			\
		Pipes/ft_create_pipes.c			\
		Utils/ft_getenv.c			\
		Pipes/ft_family_process.c		\
		Utils/ft_functions_copy.c		\
		
OBJ := $(SRC:%.c=%.o)

SANI 	:= -fsanitize=address -g3

RLFLAGS := -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include

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
