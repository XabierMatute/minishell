/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validsintax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:28:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/19 14:37:11 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ../minishell.h

int validsintax(char *s)
{
	if (!closed(s, '"'))
	{
		error_closed('"');
		return (0);
	}
	if (!closed(s, 27))
	{
		error_closed(27);
		return (0);
	}
	if (contain(s, 92))
	{
		error_contain(92);
		return (0);
	}
	if (contain(s, ';'))
	{
		error_contain(';');
		return (0);
	}	
	return (1);
}
