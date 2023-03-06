/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:48:02 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 17:59:19 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_execve_errors(char *path)
{
	if (contain(path, '/'))
	{
		if (!access(path, F_OK))
			ft_printf("%s: is a directory\n", path);
		else
			ft_printf("%s: No such file or directory\n", path);
	}
	else if (!ft_strncmp(path, ".\0", 2))
		return (ft_printf("%s: filename argument required\n", path), 2);
	else
		ft_printf("%s: command not found\n", path);
	return (127);
}

int	ft_execve(char *path, char **comands)
{
	int		res;
	char	**env;

	env = ft_transform_env();
	res = execve(path, comands, env);
	if (res == -1)
	{
		res = ft_execve_errors(path);
		ft_free_2d_arr((void **)comands);
		destroy_stack(g_cp_env);
		ft_free_2d_arr((void **)env);
		return (res);
	}
	ft_free_2d_arr((void **)env);
	return (0);
}
