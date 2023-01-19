/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:40:55 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/30 12:50:24 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	case_c(char c)
{
	ft_putchar(c);
	return (1);
}

int	case_s(char *s)
{
	unsigned int	i;

	if (!s)
		return (case_s("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	case_p(unsigned long long p)
{
	case_s("0x");
	ft_putnbr_base_vp(p, "0123456789abcdef");
	return (2 + orderof_base(p, 16));
}

int	case_(char c, va_list va)
{
	if (c == 'c')
		return (case_c(va_arg(va, int)));
	if (c == 's')
		return (case_s(va_arg(va, char *)));
	if (c == 'p')
		return (case_p((unsigned long long)va_arg(va, void *)));
	if (c == 'd' || c == 'i')
		return (case_d(va_arg(va, int)));
	if (c == 'u')
		return (case_u(va_arg(va, unsigned int)));
	if (c == 'x')
		return (case_x(va_arg(va, unsigned int)));
	if (c == 'X')
		return (case_xl(va_arg(va, int)));
	if (c == '%')
		return (case_c('%'));
	return (0);
}
