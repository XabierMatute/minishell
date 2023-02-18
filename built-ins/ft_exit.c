/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:09:12 by jperez            #+#    #+#             */
/*   Updated: 2023/02/18 11:55:52 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_exit(char **args)
{
	ft_printf("exit\n");
	if (!args || !*args)
		exit(0);
	if (ft_args_lenght(args) > 1)
	{
		ft_printf("❌ Too many arguments\n");
		return (1);
	}
	destroy_stack(G_cp_env);
	exit(ft_atoi(*args));
	return (97);
}
