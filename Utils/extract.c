/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:36:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/07 16:30:33 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	archivelen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != ' ' && s[l] != '<' && s[l] != '>')
	{
		l += ignoreq(s + l) - (s + l);
		if (s[l])
			l++;
	}
	return (l);
}

char	*extract(char *s)
{
	size_t	i;
	size_t	l;
	char	*a;

	while (*s == ' ' && *s)
		s++;
	i = 0;
	l = archivelen(s);
	a = malloc((sizeof(char) * l) + 1);
	if(!a)
		return (0);
	while (i < l)
	{
		a[i] = s[i];
		s[i] = ' ';
		i++;
	}
	a[l] = 0;
	return(a);	
}//testea esta hecho


