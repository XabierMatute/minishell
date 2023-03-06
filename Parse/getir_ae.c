/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getir_ae.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:43 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 16:55:50 by xmatute-         ###   ########.fr       */
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
		if (s[0] == '<' && s[1] == '<')
			p++;
		if (*s)
			s++;
	}
	return (p);
}

char	**getir_ae(char *s)
{
	char	**ir;
	size_t	i;

	ir = ft_calloc(redirections(s) + 1, sizeof(char *));
	i = 0;
	while (*s)
	{
		s = ignoreq(s);
		if (s[0] == '<' && s[1] == '<')
		{
			ir[i] = extract(s + 2);
			s[0] = ' ';
			s[1] = ' ';
			i++;
		}
		s++;
	}
	ir[i] = 0;
	return (ir);
}
