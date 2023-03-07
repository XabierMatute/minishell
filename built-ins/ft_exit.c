/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:09:12 by jperez            #+#    #+#             */
/*   Updated: 2023/03/07 17:45:04 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	inrange(char *s)
{
	if (!ft_strncmp("-2147483648", s, 11))
		return (1);
	if (*s == '-' || *s == '+')
		s++;
	if (ft_wlen(s, ' ') < 10)
		return (1);
	if (ft_wlen(s, ' ') > 10)
		return (0);
	if (ft_strncmp("2147483647", s, 10) < 0)
		return (0);
	return (1);
}

static int	ft_check_args(char **args)
{
	if ((args[0][0] != '-' && !ft_strisdigit(args[0]))
		|| (args[0][0] == '-' && !ft_strisdigit(args[0] + 1)))
		ft_printf("exit: %s: numeric argument required\n", args[0]);
	else if (ft_args_lenght(args) > 1)
	{
		ft_printf("❌ Too many arguments\n");
		return (1);
	}
	else if (!inrange(args[0]))
		ft_printf("exit: %s: numeric argument required\n", args[0]);
	return (0);
}

int	ft_exit(char **args)
{
	ft_printf("exit\n");
	if (!args || !*args)
		exit(0);
	if (ft_check_args(args))
		return (1);
	destroy_stack(g_cp_env);
	exit(ft_atoi(*args));
	return (97);
}
