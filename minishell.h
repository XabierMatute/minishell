/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:47:01 by jperez            #+#    #+#             */
/*   Updated: 2023/02/01 19:23:24 by jperez           ###   ########.fr       */
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

# include "./libft/libft.h"

// #include "readline/readline.h"
// #include "readline/history.h"

typedef struct node{
	char		*variable;
	struct node	*next;
}	t_node;

typedef struct stack
{
	t_node	*peek;
	int		len;
}	t_stack;

int		ft_printf(char const *s, ...);
int 	validsintax(char *s);
int 	closedq(char *s);
int	 	contain(char *s, char c);
char 	*ignore(char *s, char c);
char 	*ignoreq(char *s);
char	**liberatesl(char ***f, unsigned int p);
size_t	ft_wlen(const char *s, char c);
char	**ft_split(char const *s, char c);

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
t_stack	*ft_create_env(char **env, t_stack *stack);
t_stack	*ft_create_stack(void);
void	destroy_stack(t_stack *stack);
t_node	*ft_create_node(char *_variable);
void	delete_node(t_node *node);
void	ft_push(t_stack *stack, char *variable);
void	ft_pop(t_stack *stack, int index);

#endif
