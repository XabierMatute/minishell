/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:04:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/11 19:52:43 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void merror(void)
{
	ft_printf("⚠️Error de memoria\n");
	destroy_stack(G_cp_env);
}

int pipes(char **comands)
{
	int	i;
	int		**pipes;

	if (!comands)
		merror();
	pipes = ft_create_pipes(ft_args_lenght(comands) - 1);
	if (ft_args_lenght(comands) > 1 && !pipes)
		merror();
	// ft_family_process1(pipes, comands[0]);
	printf("----->Father: %d\n", getpid());
	i = 0;
	while (comands[i] && G_cp_env)
	{
		// if (pipes[i])
			ft_family_process(pipes, comands[i], i);
		// else if (pipes[i - 1])
		// 	ft_family_processn(pipes, comands[i], i);		
		i++;
	}
	ft_free_2d_arr(comands);
	ft_free_2d_arr(pipes);
	return (0);
}
