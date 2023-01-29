/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:37:21 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/14 21:09:41 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nstrncmp(const char *str1, const char *str2, size_t num )
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (str1[i] != str2[i])
			return (((unsigned char)str1[i] - (unsigned char)str2[i]));
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num )
{
	return (ft_nstrncmp(ptr1, ptr2, num));
}
