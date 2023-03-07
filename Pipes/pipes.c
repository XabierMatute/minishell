/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:04:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/07 16:04:05 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirecthd(char **eof)
{
	int		j;

	j = 0;
	while (eof[j])
	{
		if (ft_here_doc(eof, j))
			return (1);
		j++;
	}
	return (0);
}

int	patch(char **comands)
{
	char	**eof;
	int		i;

	i = 0;
	while (comands[++i] && g_cp_env)
	{
		if (contain(comands[i], '<'))
		{
			eof = expandall(getir_ae(comands[i]));
			if (redirecthd(eof))
				return (ft_free_2d_arr((void **)eof), 1);
			ft_free_2d_arr((void **)eof);
		}
	}
	return (0);
}

int	pipes(char **comands)
{
	int		i;
	int		**pipes;

	if (!comands)
		merror();
	pipes = ft_create_pipes(ft_args_lenght(comands) - 1);
	if (ft_args_lenght(comands) > 1 && !pipes)
		merror();
	i = -1;
	if (patch(comands))
		return (ft_update_error(1), 1);
	while (comands[++i] && g_cp_env)
		ft_family_process(pipes, comands[i], i);
	if (pipes)
		if (ft_close_pipes(pipes, 0, 1))
			rerror();
	while (i--)
		ft_waitpid(-1);
	ft_free_2d_arr((void **)comands);
	ft_free_2d_arr((void **)pipes);
	return (0);
}
