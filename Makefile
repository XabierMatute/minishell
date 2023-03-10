# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 17:35:27 by xmatute-          #+#    #+#              #
#    Updated: 2023/03/07 17:11:42 by jperez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


define HEADER

                              .,/  ,(//. .**/*   ***
                         ,. .///. ./**  .*//,  .*/(/,  .//#*
                    .. .*,  ,**. .*/*.  ,/*.  ,*/**.  .*///,
                   .,  **  .(/. ,//*  ,,*,,. *//*.  ,.,*(,.  . .*/
              .*.  ..  ..  /*,...,.. .,*,. ,///*  ,//(**. .*,*///,.
              .,  .,  .. .**,       ,,,..   .,. .,*//*. .,*((#*,. ..*((.
           ,,..,. .  ..  ,**.,*,,..,,..... ,..  .,*.  **//*/*.    ..,*,.
          ,,,.., .. .,,..*,../,,. ..,.***/*,,,../.  ,,,*/*. .,(/*,**,   ,/#
          *,..,,.*/,,**,,,..,*,...,.,*,*/.,**(/,. ..,,/,.  .///(/,. ,//(####
          ../..  ,.....//.,//.,..,.*,//,,,*/*,.***/(,.   ..,*/,  ,////((/*,
         ,,,*.*,.,... //,**/..., ,,*/.,**//,.,,*(/..,,*,,,,,. .*((((((....*/(#,
         . ,*.*./,**,**.*,,.,*,.,,/.,,*(,.,,*//,..,,,/#*,.   ,**//,. ,**,,//((*
        . .,/**.*,.,*,./*.,,,.**/,.,/(*..,*/*. ...*/*,.**,/***,, ,,*((#(/((,*..
      .. ..,**.*.*,,,.**..,..,*,.,*/.,**/(,.,.../*..///(((*, ...*/#((#/*. .*((##
     ,....,**,,,*,,*.**.,*.*,,.*,/.,**(*  .,*/*..**/(((*,*/*(//*/**.,*//(###((//
   ..,. .,./*.**,**,*.,*,,**,,**..,*/*.,,,/,.**(((/*,.***/(//*. .,,/##%((((/*,,
   ...*.,..,**,,*/*/.**,*/,***,,*(/,,**(*,,*/(#/,*/(/(((**.*/*/*///((**. .  ..*(
  ,*,*,,,.,*,*/,***,*.*/,*/*.*(/,,**#(.,*/(/*//((##(/.,,,*(((((/, ..*(((/******/
 ,..*.*/,,*/*******/*//*//,*(/.*/((,,/((*,*//((#,,*(((((#(/..,*,,,//(#(##(****.
 .(*.*****,***///*,/**(,,/(,**#/,*(#(,*//((/*,*/(#%#(,...,*/((((((((, .*.,*/(##
   */*////*///////(,(**/*./#/*/(#/*/##%/*/(((##/.**/((#(##((/*,,,**(%#%(//(#(*
     *//(//(////(/(//(**(/,###*/(#%*(#(###/*//((((###/,*//(##((/(#####(//,,
       ,/#(((((#(/((/#(*##/(#%#//##%#((/(((###(/(#####(####/*//((*(//*%#(/,,
         .#(((((#(##(%((##(###%#((%#%%#((########((((((#((/(#((########(/,
           /((#((#%%%##%&####%%%%#%%%%&%#((#######%%##(((/**//*(#((/*,,,.
            (##%#%%%%&%%%%%&&%%%%#%%%&&%#%%#((#####((######%%#%%##((//.
                %#%%%%%%%%%%%%%&&&&&%%###%%%%#%%%%%#/((%%#((%#((#%##
                  /&%%%%#&%%##################((((#((///((((((/(,
                    *&%&&&%%&&%%%%##%%#(/((#######((((##((((/
                       %##(#%%&%#%%#%#
                         (/(/*

endef
export HEADER

NAME := minishell

SRC :=	main.c					\
		minishell.c				\
		Utils/ignoreq.c			\
		Parse/validsintax.c		\
		Parse/checknoin.c		\
		Parse/checkpipes.c		\
		Parse/checkdiples.c		\
		Parse/getir_ae.c		\
		Parse/getir.c			\
		Parse/getor_ae.c		\
		Parse/getor.c			\
		Parse/expand.c			\
		Parse/expand39.c		\
		Parse/expand36.c		\
		Parse/expand34.c		\
		Utils/contain.c			\
		Utils/closed.c			\
		Utils/ft_split.c		\
		Utils/ft_wlen.c			\
		Utils/extract.c			\
		Utils/liberatesl.c		\
		Utils/ft_joinfree.c		\
		built-ins/ft_pwd.c		\
		built-ins/ft_cd.c		\
		built-ins/ft_echo.c	\
		built-ins/ft_export.c	\
		built-ins/ft_unset.c	\
		Pipes/pipes.c \
		built-ins/ft_env.c	\
		Utils/ft_args_lenght.c		\
		Utils/Errors.c				\
		built-ins/ft_manage_nodes.c	\
		built-ins/ft_manage_stack.c	\
		built-ins/ft_copy_env.c	\
		built-ins/ft_exit.c	\
		Pipes/ft_find_cmd.c			\
		Pipes/ft_create_pipes.c			\
		Utils/ft_getenv.c			\
		Pipes/ft_family_process.c		\
		Utils/ft_functions_copy.c		\
		Pipes/ft_reorganize_fds.c		\
		Signals/ft_father_signals.c		\
		Signals/ft_child_signals.c		\
		Utils/ft_free_2D_arr.c			\
		Utils/ft_strisalnum.c			\
		Utils/ft_transform_env.c			\
		built-ins/ft_manage_builtins.c	\
		Utils/ft_update_error.c			\
		redirections/ft_redirections.c	\
		redirections/ft_here_doc.c		\
		redirections/redirections.c	\
		redirections/getstdio.c	\
		redirections/resetstdio.c	\
		Utils/ft_get_next_line.c		\
		Utils/ft_strisdigit.c		\
		Pipes/ft_copy.c				\
		Utils/ft_execve.c			\
		Utils/printexport.c			\
		built-ins/ft_waitpid.c     \
		Signals/ft_redirections_signals.c	\
		Utils/ft_vlen.c					\
		
WHITE = \033[0;37m
RED = \033[0;31m
CYAN = \033[0;36m
GREEN = \033[0;32m
MAGENTA = \033[0;35m

OBJ := $(SRC:%.c=%.o)

#SANI 	:= -fsanitize=address

CC 		:= gcc -g3
CFLAGS 	:= -Wall  -Wextra -Werror  -I./readline -I./readline/include -I.  $(SANI) $(RLFLAGS)

# RLFLAGS := -L./readline -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include
RLFLAGS := -L./readline -lreadline 
LDLIBS := -lreadline -lncurses
# CFLAGS 	:= -Wall -Werror -Wextra $(SANI) $(RLFLAGS)


RM 		:= rm -rf

val 	:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

RLMAKE := readline/Makefile

.SILENT:

all : $(NAME)

$(RLMAKE) :
	cd ./readline;\
		./configure;\
	cd ..
	
$(NAME) : $(OBJ) $(RLMAKE)
	make -C libft
	@echo "Libft compiled"
	make -C ft_printf
	@echo "ft_printf compiled"
	make -C readline 2>&1 >/dev/null 
	@echo "Readline compiled"
	$(CC) $(CFLAGS) $(OBJ) readline/libhistory.a readline/libreadline.a ft_printf/libftprintf.a libft/libft.a $(LDLIBS) -o $(NAME)
	@echo "$(GREEN)Minishell compiled...$(WHITE)"
	@echo "$(MAGENTA)$$HEADER$(WHITE)"
	# $(CC) $(CFLAGS) $(OBJ) ft_printf/libftprintf.a libft/libft.a   readline/libhistory.a readline/libreadline.a -o $(NAME)

clean :
		$(RM) $(OBJ)
		make clean -C libft
		make clean -C ft_printf
		make clean -C readline
		@echo "$(RED)clean done...$(WHITE)"

fclean : clean
		make fclean -C libft
		make fclean -C ft_printf
		$(RM) $(NAME)
		@echo "$(RED)fclean done...$(WHITE)"

re : fclean all

.PHONY : all clean fclean re
