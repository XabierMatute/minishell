/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:48:02 by jperez            #+#    #+#             */
/*   Updated: 2023/02/24 17:42:52 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_execve_errors(char *path)
{
	if (contain(path, '/'))
	{
		if (!access(path, F_OK))
			ft_printf("%s: is a directory\n", path);
		else
			ft_printf("%s: No such file or directory\n", path);
	}
	else if (!ft_strncmp(path, ".\0", 2))
		ft_printf("%s: filename argument required\n", path);
	else
		ft_printf("%s: command not found\n", path);
}

int	ft_execve(char *path, char **comands)
{
	int		res;
	char	**env;

	env = ft_transform_env();
	res = execve(path, comands, env);
	if (res  == -1)//hacer esto mejor
	{
		ft_execve_errors(path);
		ft_free_2d_arr((void **)comands);
		destroy_stack(G_cp_env);
		ft_free_2d_arr((void **)env);
		return (127);
	}
	ft_free_2d_arr((void **)env);
	return (0);
}
