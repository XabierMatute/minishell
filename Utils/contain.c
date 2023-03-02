/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:34:42 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/02 18:59:46 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	contain(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (1);
		}
		s++;
	}
	return (0);
}

int	prepcontain(char *s, char c)
{
	while (*s)
	{
		s = ignoreq(s);
		if (*s == c)
		{
			return (1);
		}
		s++;
	}
	return (0);
}
