/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand36.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:02:50 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 16:58:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	e36len(char *s)
{
	size_t	l;

	if (*s == '?')
		return (1);
	l = 0;
	while (s[l] && (ft_isalnum(s[l]) || s[l] == '_'))
		l++;
	return (l);
}

char	*expand36(char *s)
{
	char	*v;
	char	*e;
	size_t	l;

	if (!s)
		return (0);
	l = e36len(s);
	if (!l)
		return (ft_strjoinfree(ft_strdup("$"), expand(s)));
	if (!*s)
		return (ft_strdup(""));
	v = ft_calloc(l + 1, sizeof(char));
	if (!v)
		return (0);
	while (l--)
		v[l] = s[l];
	if (ft_getenv(v))
		e = ft_strdup(ft_getenv(v));
	else
		e = ft_strdup("");
	l = ft_strlen(v);
	free(v);
	return (ft_strjoinfree(e, expand(s + l)));
}
