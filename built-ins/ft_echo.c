/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:55:19 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 16:50:44 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
	}
}

void	ft_print_n_args(char **args)
{
	if (*args)
		ft_print_args(args);
	ft_printf("\n");
}

int	ft_echo(char **args)
{
	if (*args)
	{
		if (!ft_strncmp(*args, "-n\0", 3))
			ft_print_args(++args);
		else
			ft_print_n_args(args);
	}
	else
		ft_printf("\n");
	return (0);
}
