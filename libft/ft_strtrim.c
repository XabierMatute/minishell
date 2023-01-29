/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 21:20:15 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/22 19:33:49 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pertenece(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	while (pertenece(set, s1[i]))
		i++;
	start = i;
	while (s1[i + 1])
		i++;
	while (pertenece(set, s1[i]) && i)
		i--;
	return (ft_substr(s1, start, i - start + 1));
}
