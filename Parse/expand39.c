/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand39.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:13:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 16:57:23 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	e39len(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != 39)
		l++;
	return (l);
}

char	*expand39(char *s)
{
	char	*e;
	size_t	l;

	if (!s)
		return (0);
	if (!*s)
		return (ft_strdup(""));
	l = e39len(s);
	e = ft_calloc(l + 1, sizeof(char));
	if (!e)
		return (merror(), NULL);
	while (l--)
		e[l] = s[l];
	return (ft_strjoinfree(e, expand(s + ft_strlen(e) + 1)));
}
