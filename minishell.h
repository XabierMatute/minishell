/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:25:59 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 16:39:49 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <readline/readline.h>
#include <readline/history.h>


// #include "readline/readline.h"
// #include "readline/history.h"


int		ft_printf(char const *s, ...);
int 	validsintax(char *s);
int 	closedq(char *s);
int	 	contain(char *s, char c);
char *ignore(char *s, char c);
char 	*ignoreq(char *s);
#endif
