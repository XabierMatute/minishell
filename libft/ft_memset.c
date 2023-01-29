/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:31:47 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/09 21:46:00 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)(str + i)) = (unsigned char)c;
		i++;
	}
	return (str);
}
