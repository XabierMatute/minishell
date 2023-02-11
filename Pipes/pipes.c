/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:04:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/11 21:42:44 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int pipes(char **comands)
{
	int	i;
	int		**pipes;

	if (!comands)
		merror();
	pipes = ft_create_pipes(ft_args_lenght(comands) - 1);
	if (ft_args_lenght(comands) > 1 && !pipes)
		merror();
					printf("----->Father: %d\n", getpid());
	i = 0;
	while (comands[i] && G_cp_env)
	{
		ft_family_process(pipes, comands[i], i);	
		i++;//ponlo en una linea si quieres
	}
	ft_free_2d_arr(comands);
	ft_free_2d_arr(pipes);
	return (0);
}
