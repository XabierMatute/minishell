/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:41:48 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/31 17:44:22 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static unsigned int	palabras(char const *s, char c)
{
	unsigned int	p;

	p = 0;
	while (*(s))
	{
		s = ignoreq(s);
		if ((s[1] == 0 || s[1] == c) && s[0] != c)
			p++;
		if ((s[1] == 0 || s[1] == c) && s[0] != c)
			p++;
		s++;
	}
	return (p);
}

char	**breaker(char *s)
{
	
}