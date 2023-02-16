/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:10:30 by jperez            #+#    #+#             */
/*   Updated: 2023/02/15 17:40:14 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_execve(char *path, char **comands)
{
	char **env;

	env = ft_transform_env();
	if (execve(path, comands, env)  == -1)//hacer esto mejor
	{
		perror("");
		free(env);
		return (1);
	}
	free(env);
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
