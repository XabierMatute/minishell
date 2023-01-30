/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validsintax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:28:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/30 18:43:44 by xmatute-         ###   ########.fr       */
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

int validsintax(char *s)
{
	return (checkclosed(s) &&
			checkcontain(s, 92) &&
			checkcontain(s, '(') &&
			checkcontain(s, ')') &&
			checkcontain(s, '*') &&
			checkcontain(s, ';'));
}


/*
** no entender || y && y que haya varios ||| contrabarras en cualquier sitio | al principio
*/


/*
** 39  '
** 92  \
*/

/*
** expandir las variables y eliminr las comillas lo que sea que es $?
*/