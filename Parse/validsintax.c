/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validsintax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:28:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/19 14:44:14 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ../minishell.h

static int	checkclosed(char *s, char c)
{
	if (!closed(s, c))
	{
		error_closed(c);
		return (0);
	}
	return (1);
}

static int	checkcontain(char *s, char c)
{
	if (!contain(s, c))
	{
		error_contain(c);
		return (0);
	}
	return (1);
}

int validsintax(char *s)
{
	return (checkclosed(s, '"') &&
			checkclosed(s, ''') &&
			checkcontain(s, '\') &&
			checkcontain(s, ';'));
}
