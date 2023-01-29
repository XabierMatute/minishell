/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignoreq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:23:36 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 16:35:20 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ignore(char *s, char c)
{
		if (*s == c)
		{
			s++;
			while (*s != c && *s)
				s++;
		}
		return (s);
}

char *ignoreq(char *s)
{
	s = ignore(s, '"');
	s = ignore(s, 39);
	return (s);
}