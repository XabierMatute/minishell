# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:33:39 by xmatute-          #+#    #+#              #
#    Updated: 2023/01/29 17:13:04 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

SRC :=	main.c  \
		Utils/ignoreq.c	\
		Parse/validsintax.c \
		Utils/contain.c	\
		Utils/closed.c	\
		Utils/ft_split.c \
		Utils/ft_wlen.c \
		Utils/liberatesl.c \

		
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