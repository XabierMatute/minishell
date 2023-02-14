/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:55:19 by jperez            #+#    #+#             */
/*   Updated: 2023/02/14 13:31:03 by xmatute-         ###   ########.fr       */
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
	if(*args)
		ft_print_args(args);
	ft_printf("\n");
}

void	ft_echo(char **args)
{
	if (*args)
		if (ft_strncmp(*args, "-n", 2))
		{
			args++;
			ft_print_args(args);
		}
	else
		ft_print_n_args(args);

		
	exit (55);
}
