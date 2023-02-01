/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:12:30 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/01 18:14:28 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	checkclosed(char *s)
{
	if (!closedq(s))
	{
		ft_printf("😞Error: no interpreto comillas sin cerrar\n");
		return (0);
	}
	return (1);
}

static int	checkcontain(char *s, char c)
{
	if (contain(s, c))
	{
		ft_printf("😞Error: no interpreto el caracter especial %c\n", c);
		return (0);
	}
	return (1);
}

int	checknoin(char *s)
{
		return (checkclosed(s) &&
				checkcontain(s, 92) &&
				checkcontain(s, '(') &&
				checkcontain(s, ')') &&
				checkcontain(s, '*') &&
				checkcontain(s, ';'));
}