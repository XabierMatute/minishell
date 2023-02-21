/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand36.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:02:50 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/21 18:43:38 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t e36len(char *s)
{
	size_t	l;

	if (*s == '?')
		return (1);
	
	l = 0;
	while (s[l] && (ft_isalnum(s[l]) || s[l] == '_'))
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
	l = e36len(s);
	if (!l)
		return(ft_strjoinfree(ft_strdup("$"), expand(s)));
	if (!*s)
		return(ft_strdup(""));
	
	
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
