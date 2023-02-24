/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:10:30 by jperez            #+#    #+#             */
/*   Updated: 2023/02/23 18:08:39 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_execve(char *path, char **comands)
{
	int		res;
	char	**env;

	env = ft_transform_env();
	res = execve(path, comands, env);
	if (res  == -1)//hacer esto mejor
	{
		if (path[0] == '.' || path[0] == '/')
			perror("");
		else
			printf("😥 %s: Command not found\n", path);
		ft_free_2d_arr((void **)comands);
		destroy_stack(G_cp_env);
		ft_free_2d_arr((void **)env);
		return (127);
	}
	ft_free_2d_arr((void **)env);
	return (0);
}
 
int	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_close(int pipe)
{
	if (close(pipe) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_pipe(int *fds)
{
	if (pipe(fds) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_siagction(int signal, type_sa *sa)
{
	if (sigaction(signal, sa, NULL) == -1)
    {
        perror("sigaction");
        return (1);
    }
	return (0);
}
