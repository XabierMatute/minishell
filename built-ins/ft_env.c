/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:06:13 by jperez            #+#    #+#             */
/*   Updated: 2023/02/01 19:23:42 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_env(t_stack *cp_env, char **args)
{
	t_node *ptr;

	if (ft_args_lenght(args) != 0)
	{
		ft_printf("❌ env: to many arguments\n");
		return ;
	}
	if (cp_env->peek)
	{
		if (cp_env->peek->next)
		{
			ptr = cp_env->peek;
			while (ptr)
			{
				printf("%s\n", ptr->variable);
				ptr = ptr->next;
			}
		}
	}
}
