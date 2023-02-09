/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getor_ae.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:43 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/07 11:36:46 by xmatute-         ###   ########.fr       */
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
		if (s[0] == '>' && s[1] == '>')
			p++;
		if (*s)
			s++;
	}
	return (p);
}



char	**getor_ae(char *s)
{
	char	**or;
	size_t	i;

	or = ft_calloc(redirections(s) + 1, sizeof(char *));
	i = 0;
	while (*s)
	{
		s = ignoreq(s);
		if (s[0] == '>' && s[1] == '>')
		{
			or[i] = extract(s + 2);
			s[0] = ' ';
			s[1] = ' ';
			i++;
		}
		s++;
	}
	or[i] = 0;
	return(or);
}
