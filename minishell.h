/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:47:01 by jperez            #+#    #+#             */
/*   Updated: 2023/01/31 19:42:29 by jperez           ###   ########.fr       */
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
void	ft_export(char **env, char **variables);
void 	pipes(char **comands);
void ft_env(char **env);
int	ft_args_lenght(char **args);

#endif
