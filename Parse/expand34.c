/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand34.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:13:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/15 17:52:34 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t e34len(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != 34 && s[l] != 36)
		l++;
	return (l);
}

char *expand3634(char *s)
{
	char	*v;
	char	*e;
	size_t	l;
	
	// printf("s39 = %s\n", s);
	if (!s)
		return(0);
	if (!*s)
		return(ft_strdup(""));
	l = e36len(s);
	// printf("l39 = %i\n", l);

	v = ft_calloc(l + 1, sizeof(char));
	if (!v)
		return(0);//printear error de memoria
	
	while (l--)
	{
		// printf("e[%i] = %c\n", l, s[l]);

		v[l] = s[l];
	}
	// printf("e39 = %s\n", e);
	if (ft_getenv(v))
		e = ft_strdup(ft_getenv(v));
	else
		e = ft_strdup("");
	l = ft_strlen(v);
	free(v);

	return (ft_strjoinfree(e, expand34(s + l)));
}

char *expand34(char *s)
{
	char	*e;
	size_t	l;
	
	// printf("s34 = %s\n", s);
	if (!s)
		return(0);
	if (!*s)
		return(ft_strdup(""));
	if (*s == 36)
		return (expand3634(s + 1));
	if (*s == 34)
		return (expand(s + 1));
	l = e34len(s);
	// printf("l39 = %i\n", l);

	e = ft_calloc(l + 1, sizeof(char));
	if (!e)
		return(0);//printear error de memoria
	
	while (l--)
	{
		// printf("e[%i] = %c\n", l, s[l]);

		e[l] = s[l];
	}
	// printf("e39 = %s\n", e);

	return (ft_strjoinfree(e, expand34(s + ft_strlen(e))));
}
