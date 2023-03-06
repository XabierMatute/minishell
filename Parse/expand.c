/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:23:19 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 16:31:26 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	elen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != 39 && s[l] != 36 && s[l] != 34)
		l++;
	return (l);
}

char	*expand(char *s)
{
	char	*e;
	size_t	l;

	if (!s)
		return (0);
	if (!*s)
		return (ft_strdup(""));
	if (*s == 39)
		return (expand39(s + 1));
	if (*s == 36)
		return (expand36(s + 1));
	if (*s == 34)
		return (expand34(s + 1));
	l = elen(s);
	e = ft_calloc(l + 1, sizeof(char));
	if (!e)
		return (merror(), NULL);
	while (l--)
		e[l] = s[l];
	return (ft_strjoinfree(e, expand(s + ft_strlen(e))));
}

char	**expandall(char **ss)
{
	char	**e;
	size_t	i;

	if (!ss)
		return (0);
	e = malloc(sizeof(char *) * (ft_args_lenght(ss) + 1));
	if (!e)
		return (ft_free_2d_arr((void **)ss), (char **)0);
	i = 0;
	while (ss[i])
	{
		e[i] = expand(ss[i]);
		if (!e[i])
		{
			ft_free_2d_arr((void **)e);
			ft_free_2d_arr((void **)ss);
			return (0);
		}
		i++;
	}
	e[i] = 0;
	ft_free_2d_arr((void **)ss);
	return (e);
}
