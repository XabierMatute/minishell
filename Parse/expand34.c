/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand34.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:13:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 16:32:05 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	size_t	e34len(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != 34 && s[l] != 36)
		l++;
	return (l);
}

char	*expand3634(char *s)
{
	char	*v;
	char	*e;
	size_t	l;

	if (!s)
		return (0);
	if (!*s)
		return (ft_strdup(""));
	l = e36len(s);
	if (!l)
		return (ft_strjoinfree(ft_strdup("$"), expand34(s)));
	v = ft_calloc(l + 1, sizeof(char));
	if (!v)
		return (merror(), NULL);
	while (l--)
		v[l] = s[l];
	if (ft_getenv(v))
		e = ft_strdup(ft_getenv(v));
	else
		e = ft_strdup("");
	l = ft_strlen(v);
	free(v);
	return (ft_strjoinfree(e, expand34(s + l)));
}

char	*expand34(char *s)
{
	char	*e;
	size_t	l;

	if (!s)
		return (0);
	if (!*s)
		return (ft_strdup(""));
	if (*s == 36)
		return (expand3634(s + 1));
	if (*s == 34)
		return (expand(s + 1));
	l = e34len(s);
	e = ft_calloc(l + 1, sizeof(char));
	if (!e)
		return (merror(), NULL);
	while (l--)
		e[l] = s[l];
	return (ft_strjoinfree(e, expand34(s + ft_strlen(e))));
}
