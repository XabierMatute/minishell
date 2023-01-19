/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:25:45 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/30 13:11:27 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(char const *s, ...)
{
	int			i;
	int			r;
	va_list		va;

	i = 0;
	r = 0;
	va_start(va, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			r = r + case_(s[i], va);
		}
		else
		{
			ft_putchar(s[i]);
			r++;
		}
		i++;
	}
	va_end(va);
	return (r);
}
