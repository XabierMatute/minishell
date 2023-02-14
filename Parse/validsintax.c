/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validsintax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:28:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/13 20:39:56 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



int validsintax(char *s)
{
	return (checknoin(s) &&
			checkpipes(s) &&
			checkdiples(s));
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