/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:24:46 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/21 18:33:28 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putposnbr_fd(unsigned int n, int fd)
{
	if (n / 10 == 0)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putposnbr_fd(n / 10, fd);
		ft_putposnbr_fd(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putposnbr_fd(-1 * n, fd);
	}
	else
		ft_putposnbr_fd(n, fd);
}
