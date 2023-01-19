/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:25:59 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/19 18:32:56 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
int				ft_printf(char const *s, ...);
int validsintax(char *s);
int closed(char *s, char c);
int contain(char *s, char c);
char *ignoreq(char *s);
#endif
