/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:41:27 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/21 18:43:16 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	p10(unsigned int n)
{
	if (n == 0)
		return ((unsigned long long int)1);
	else if (0 < n && n < 20)
		return ((unsigned long long int)(10 * p10(n - 1)));
	else
		return (0);
}

static char	*positoadr(char *a, unsigned int n, size_t d)
{
	size_t			i;

	i = 0;
	while (i < d)
	{
		a [i] = '0' + n / p10(d - i - 1);
		n = n % p10(d - i - 1);
		i++;
	}
	a[d] = 0;
	return (a);
}

static char	*negitoadr(char *a, unsigned int n, size_t d)
{
	*a = '-';
	positoadr(a + 1, n * -1, d);
	return (a);
}

static unsigned int	ordende(int numero)
{
	unsigned int	i;
	int				s;

	i = 0;
	s = 0;
	if (numero < 0)
		s = 1;
	if (numero == 0)
		return (1);
	while ((int) numero / ((int)p10(i)) && i < 10)
		i++;
	return (i + s);
}

char	*ft_itoa(int n)
{
	char	*a;

	a = malloc((ordende(n) + 1) * sizeof(char));
	if (!a)
		return (0);
	if (n >= 0)
		return (positoadr(a, n, ordende(n)));
	else
		return (negitoadr(a, n, ordende(n) - 1));
	return (0);
}
