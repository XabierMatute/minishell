/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:43 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/07 12:03:30 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static unsigned int	redirections(char *s)
{
	unsigned int	p;

	p = 0;
	while (*(s))
	{
		s = ignoreq(s);
		if (*s == '<')
			p++;
		s++;
	}
	return (p);
}

char	**getir(char *s)
{
	char	**ir;
	size_t	i;

	ir = ft_calloc(redirections(s) + 1, sizeof(char *));
	i = 0;
	while (*s)
	{
		s = ignoreq(s);
		if (*s == '<')
		{
			ir[i] = extract(s + 1);
			s[0] = ' ';
			i++;
		}
		s++;
	}
	ir[i] = 0;
	return(ir);
}