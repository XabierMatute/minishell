/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:17:34 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 17:02:51 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	s = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	free(s1);
	free(s2);
	return (s);
}
