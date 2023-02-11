/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand39.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:13:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/10 15:53:03 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t e39len(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != 39)
		l++;
	return (l);
}

char *expand39(char *s)
{
	char	*e;
	size_t	l;
	
	// printf("s39 = %s\n", s);
	if (!s)
		return(0);
	if (!*s)
		return(ft_strdup(""));
	l = e39len(s);
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

	return (ft_strjoinfree(e, expand(s + ft_strlen(e) + 1)));
}
