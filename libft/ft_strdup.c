/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:56:25 by xmatute-          #+#    #+#             */
/*   Updated: 2022/12/06 20:21:08 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup( const char *str1)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(sizeof(char) * (ft_strlen(str1) + 1));
	if (!s)
		return (0);
	while (str1[i])
	{
		s[i] = str1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
