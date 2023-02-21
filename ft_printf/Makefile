# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 18:25:48 by xmatute-          #+#    #+#              #
#    Updated: 2023/02/21 16:05:31 by jperez           ###   ########.fr        #
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

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
# 	echo "Library Compiled with bonus"

.PHONY: all clean fclean re bonus
