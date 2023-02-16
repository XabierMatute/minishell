/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:06:13 by jperez            #+#    #+#             */
/*   Updated: 2023/02/16 14:52:35 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_check_args(char **args)
{
	if (ft_args_lenght(args) != 0)
	{
		ft_printf("❌ env: to many arguments\n");
		return (1);
	}
	return (0);
}

int ft_env(char **args)
{
	t_node *ptr;

	if (ft_check_args(args))
		return (55);
	if (G_cp_env->peek)
	{
		if (G_cp_env->peek->next)
		{
			ptr = G_cp_env->peek;
			while (ptr)
			{
				if (ft_strncmp(ptr->variable, "?" , 1))
					ft_printf("%s\n", ptr->variable);
				ptr = ptr->next;
			}
		}
	}
	return (55);
}
