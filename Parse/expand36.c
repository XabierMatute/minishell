/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand36.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:02:50 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/15 17:52:15 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t e36len(char *s)
{
	size_t	l;

	if (*s == '?')
		return (1);
	
	l = 0;
	while (s[l] && ft_isalnum(s[l]))
		l++;
	return (l);
}

char *expand36(char *s)
{
	char	*v;
	char	*e;
	size_t	l;
	
	// printf("s36 = %s\n", s);
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

	return (ft_strjoinfree(e, expand(s + l)));
}
