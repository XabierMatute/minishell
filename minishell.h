/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:47:01 by jperez            #+#    #+#             */
/*   Updated: 2023/02/09 18:04:04 by jperez           ###   ########.fr       */
/*   Updated: 2023/02/01 18:34:47 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>

# include "./libft/libft.h"

// #include "readline/readline.h"
// #include "readline/history.h"
typedef struct sigaction type_sa;

typedef struct node{
	char		*variable;
	struct node	*next;
}	t_node;

typedef struct stack
{
	t_node	*peek;
	int		len;
}	t_stack;

t_stack	*G_cp_env;


int		ft_printf(char const *s, ...);
int 	validsintax(char *s);
int 	closedq(char *s);
int	 	contain(char *s, char c);
char 	*ignore(char *s, char c);
char 	*ignoreq(char *s);
char	**liberatesl(char ***f, unsigned int p);
size_t	ft_wlen(const char *s, char c);
char	**ft_split(char const *s, char c);
int		checknoin(char *s);
int		checkpipes(char *s);

/* ------------------- BUILT_INS ---------------------*/
void	ft_cd(char **args);
void	ft_pwd();
void	ft_echo(char **args);
void	ft_export(t_stack *cp_env, char **variables);
void 	pipes(char **comands);
void ft_env(t_stack *cp_env, char **args);
int	ft_args_lenght(char **args);
void	ft_unset(t_stack *cp_env, char **args);
void	ft_exit(t_stack *cp_env);

/* ------------------- MANAGE-ENV-NODES ---------------------*/
t_stack	*ft_create_env(char **env);
t_stack	*ft_create_stack(void);
void	destroy_stack(t_stack *stack);
t_node	*ft_create_node(char *_variable);
void	delete_node(t_node *node);
void	ft_push(t_stack *stack, char *variable);
void	ft_pop(t_stack *stack, int index);

/* ------------------- SIGNAALS ---------------------*/
int ft_add_listener();
int ft_add_parent_listener();
int ft_add_child_listener();
int	ft_siagction(int signal, type_sa *sa);
void	ft_sigint_action();

/* ------------------- PIPES ---------------------*/
char *ft_find_cmd(char *cmd);
int	**ft_create_pipes(int pipes_num);
int	ft_family_process(int **pipes, char **comands, int i);
int	ft_dup2_fds(int read_fd, int write_fd);
int	ft_close_pipes(int **pipes, int read_fd, int write_fd);

/* ------------------- MANAGE-ENV-NODES ---------------------*/
char *ft_getenv(char *path);

/* ------------------- UTILS ---------------------*/
int	ft_execve(char *path, char **comands);
int	ft_dup2(int fd1, int fd2);
int	ft_close(int pipe);
int	ft_pipe(int *fds);


#endif
