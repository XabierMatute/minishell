/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:31:48 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/19 16:58:29 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_strlen(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[0];
	while (c != 0)
	{
		if ((c == '+') || (c == '-'))
			return (0);
		i++;
		c = str[i];
	}
	return (i);
}

static int	letrasrepes(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = str[0];
	while (c != 0)
	{
		j = i + 1;
		while (str[j] != 0)
		{
			if (str[j] == c)
				return (1);
			j++;
		}
		i++;
		c = str[i];
	}
	return (0);
}

static void	recursive(long long nbr, char *base, unsigned int b)
{
	if (nbr < b)
		ft_putchar(base[(int)nbr]);
	else
	{
		recursive(nbr / b, base, b);
		ft_putchar(base[nbr % b]);
	}
}

void	ft_putnbr_base(long long nbr, char *base)
{
	unsigned int	b;

	b = ft_strlen(base);
	if ((b > 1) && (letrasrepes(base) == 0))
	{
		recursive(nbr, base, b);
	}
}
