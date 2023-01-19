/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:28:21 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/30 13:01:27 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

unsigned long long	power_n(long long x, unsigned int n)
{
	if (n == 0)
		return ((unsigned long long int)1);
	else if (0 < n && n < 20)
		return ((unsigned long long int)(x * power_n(x, (n - 1))));
	else
		return (0);
}

unsigned int	orderof_base(unsigned long long num, int base)
{
	unsigned int	i;

	if (base == 16 && num > power_n(16, 15))
	{
		return (16);
	}
	if (num == 0)
		return (1);
	i = 0;
	while (num / power_n(base, i))
	{
		i++;
	}
	return (i);
}
