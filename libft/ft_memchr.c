/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:09:22 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/22 11:52:31 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	cc;
	size_t			i;

	s = (unsigned char *)str;
	cc = c;
	i = 0;
	while (i < n)
		if (s[i++] == cc)
			return (s + i - 1);
	return (0);
}
