/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validsintax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:28:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/19 17:17:26 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	checkclosed(char *s, char c)
{
	if (!closed(s, c))
	{
		ft_printf("Error: hay %c sin cerrar\n", c);
		return (0);
	}
	return (1);
}

static int	checkcontain(char *s, char c)
{
	if (contain(s, c))
	{
		ft_printf("Error: no interpreto el caracter especial %c\n", c);
		return (0);
	}
	return (1);
}

int validsintax(char *s)
{
	return (checkclosed(s, '"') &&
			checkclosed(s, 39) &&
			checkcontain(s, 92) &&
			checkcontain(s, ';'));
}

/*
** 39  '
** 92  \
*/