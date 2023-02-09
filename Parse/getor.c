/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:33:42 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/07 11:49:27 by xmatute-         ###   ########.fr       */
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
		if (*s == '>')
			p++;
		s++;
	}
	return (p);
}

char	**getor(char *s)
{
	char	**or;
	size_t	i;

	or = ft_calloc(redirections(s) + 1, sizeof(char *));
	i = 0;
	while (*s)
	{
		s = ignoreq(s);
		if (*s == '>')
		{
			or[i] = extract(s + 1);
			s[0] = ' ';
			i++;
		}
		s++;
	}
	or[i] = 0;
	return(or);
}