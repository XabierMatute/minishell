/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncases.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:43:01 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/30 13:06:02 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	case_d(int d)
{
	ft_putnbr_base(d, "0123456789");
	if (d < 0)
		return (orderof_base(((long long)d * -1), 10) + 1);
	return (orderof_base(d, 10));
}

int	case_u(unsigned int u)
{
	ft_putnbr_base(u, "0123456789");
	return (orderof_base(u, 10));
}

int	case_x(unsigned int x)
{
	ft_putnbr_base(x, "0123456789abcdef");
	return (orderof_base(x, 16));
}

int	case_xl(unsigned int x)
{
	ft_putnbr_base(x, "0123456789ABCDEF");
	return (orderof_base(x, 16));
}
