# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 18:25:48 by xmatute-          #+#    #+#              #
#    Updated: 2022/09/30 12:54:55 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

.SILENT:

SRC =	ft_printf.c \
		cases.c     ncases.c\
		ft_putnbr_base.c    \
		ft_putnbr_base_vp.c \
		order.c


		
# ft_.c

OBJS = $(SRC:%.c=%.o)

BONUS =	*_bonus.c
		
BONUS_OBJS = $(BONUS:%.c=%.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

.c.o: $(SRC)
	${CC} ${FLAGS} -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	echo "Library compiled"

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	echo ".o files removed"

fclean: clean
	rm -f $(NAME)
	echo "Library removed"

re: fclean $(NAME)

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
# 	echo "Library Compiled with bonus"

.PHONY: all clean fclean re bonus
