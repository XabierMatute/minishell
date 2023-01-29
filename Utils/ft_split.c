/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:51:11 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 18:02:13 by xmatute-         ###   ########.fr       */
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
		s++;
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char			**sl;
	unsigned int	i;
	unsigned int	p;

	sl = malloc(sizeof(char *) * (palabras(s, c) + 1));
	if (!sl)
		return (0);
	i = 0;
	p = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		sl[p] = ft_substr(s, i, ft_wlen(s + i, c));
		if (!sl[p])
			return (liberatesl(&sl, p));
		p++;
		i = i + ft_wlen(s + i, c);
		while (s[i] == c && s[i])
			i++;
	}
	sl[p] = 0;
	return (sl);
}
