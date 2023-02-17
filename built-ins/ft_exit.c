/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:09:12 by jperez            #+#    #+#             */
/*   Updated: 2023/02/17 17:59:31 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_exit(char **args)
{
	if (ft_args_lenght(args) > 1)
	{
		ft_printf("❌ Too many arguments\n");
		return (1);
	}
	ft_printf("exit\n");
	destroy_stack(G_cp_env);
	exit(ft_atoi(*args));
	return (97);
}
