/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:22:41 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/13 15:05:58 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_imemcpy(void *destination, const void *source, size_t num)
{
	unsigned int	i;

	i = num;
	while (i--)
		((char *)(destination))[i] = ((char *)(source))[i];
	return (destination);
}

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	if (!destination && !source)
		return (0);
	if (destination < source)
		return (ft_memcpy(destination, source, num));
	else if (destination > source)
		return (ft_imemcpy(destination, source, num));
	else
		return (destination);
}
