/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:47:01 by jperez            #+#    #+#             */
/*   Updated: 2023/03/07 17:11:17 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <curses.h>
# include <ncurses.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>
# include "./libft/libft.h"
# include "./readline/readline.h"
# include "./readline/history.h"

# define STARTED	1
# define NO_STARTED	0

# define START		0
# define END		1
# define MIDDLE		2

typedef struct sigaction	t_type_sa;
typedef struct node{
	char		*variable;
	struct node	*next;
}	t_node;

typedef struct stack
{
	t_node	*peek;
	int		len;
}	t_stack;

t_stack						*g_cp_env;

int		minishell(void);

int		ft_printf(char const *s, ...);

/* ------------------- CHECKS ---------------------*/
int		validsintax(char *s);
int		checknoin(char *s);
int		checkpipes(char *s);
int		checkdiples(char *s);
int		closedq(char *s);

/* ------------------- PARSE ---------------------*/
char	**expandall(char **ss);
char	*expand(char *s);
char	*expand39(char *s);
char	*expand36(char *s);
char	*expand34(char *s);
size_t	e36len(char *s);

/* ------------------- BUILT_INS ---------------------*/
int		is_builtin(char **comands);
int		ft_cd(char **args);
int		ft_pwd(char **args);
int		ft_echo(char **args);
int		ft_export(char **variables);
int		ft_env(char **args);
int		ft_args_lenght(char **args);
int		ft_unset(char **args);
int		ft_exit(char **args);
int		ft_manage_builtins(char **comands);
char	*ft_getpwd(void);
int		ft_print_export_env(void);
int		ft_check_variable_name(char *variable);
void	ft_waitpid(int pid);

/* ------------------- MANAGE-ENV-NODES ---------------------*/
t_stack	*ft_create_env(char **env);
t_stack	*ft_create_stack(void);
void	destroy_stack(t_stack *stack);
t_node	*ft_create_node(char *_variable);
void	delete_node(t_node *node);
void	ft_push(t_stack *stack, char *variable);
void	ft_pop(t_stack *stack, int index);

/* ------------------- SIGNAALS ---------------------*/
int		ft_add_listener(void);
int		ft_add_father_listener(void);
int		ft_add_child_listener(void);
int		ft_add_redirections_listener(void);
int		ft_siagction(int signal, t_type_sa *sa);
void	ft_manage_here_doc_signals(int signum);
void	ft_sigint_action(void);

/* ------------------- PIPES ---------------------*/
int		pipes(char **comands);
char	*ft_find_cmd(char *cmd);
int		**ft_create_pipes(int pipes_num);
int		ft_family_process(int **pipes, char *comand, int i);
int		ft_dup2_fds(int **pipes, int read_fd, int write_fd);
int		ft_close_pipes(int **pipes, int read_fd, int write_fd);
char	**ft_copy(char **comands, char *path, int comands_len);

/* ------------------- MANAGE-ENV-NODES ---------------------*/
char	*ft_getenv(char *path);

/* ------------------- UTILS ---------------------*/
int		ft_execve(char *path, char **comands);
int		ft_dup2(int fd1, int fd2);
int		ft_close(int pipe);
int		ft_pipe(int *fds);
void	ft_free_2d_arr(void **arr);
int		ft_strisalnum(char *str);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ignore(char *s, char c);
char	*ignoreq(char *s);
int		contain(char *s, char c);
int		prepcontain(char *s, char c);
char	*extract(char *s);
size_t	ft_wlen(char *s, char c);
char	**ft_split(char *s, char c);
char	**liberatesl(char ***f, unsigned int p);
char	**ft_transform_env(void);
void	ft_update_error(int n);
t_node	*ft_getenv_node(char *variable);
char	*ft_get_next_line(int fd);
int		ft_strisdigit(char *str);
int		ft_execve(char *path, char **comands);

int		printexport(char	*s);
size_t	ft_vlen(char *s);

/* ------------------- REDIRECTIONS ---------------------*/
int		makeredirections(char *comand);
int		ft_here_doc(char **eof, int i);
int		ft_redirect_output(char *path, int flag);
int		ft_redirect_input(char *path);

int		*getstdio(int stdio[2]);
int		*resetstdio(int stdio[2]);

char	**getir_ae(char *s);
char	**getir(char *s);
char	**getor(char *s);
char	**getor_ae(char *s);

/* ------------------- ERRORS ---------------------*/
int		merror(void);
int		rerror(void);
int		serror(void);

#endif
