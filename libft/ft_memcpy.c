/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:00:06 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/13 15:03:12 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned int	i;

	if (!destination && !source)
		return (0);
	i = 0;
	while (i < num)
	{
		((char *)(destination))[i] = ((char *)(source))[i];
		i++;
	}
	return (destination);
}
