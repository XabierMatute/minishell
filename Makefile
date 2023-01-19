# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 19:33:39 by xmatute-          #+#    #+#              #
#    Updated: 2023/01/19 15:34:09 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

SRC :=	main.c  \
		closed.c	\

		
OBJ := $(SRC:%.c=%.o)

SANI 	:= -fsanitize=address -g3

CC 		:= gcc
CFLAGS 	:= -Wall  -Wextra -Werror $(SANI)
# CFLAGS 	:= -Wall -Werror -Wextra $(SANI)

RM 		:= rm -rf

val 	:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C ft_printf
	$(MAKE) -C mlx 2> logs
	rm -f logs
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -Imlx $(OBJ) ft_printf/libftprintf.a libft/libft.a mlx/libmlx.a -o $(NAME)

clean :
		$(RM) $(OBJ)
		make clean -C libft
		make clean -C ft_printf
		make clean -C mlx

fclean : clean
		make fclean -C libft
		make fclean -C ft_printf
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re