/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:33:51 by jperez            #+#    #+#             */
/*   Updated: 2023/02/07 18:53:06 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_close(int pipe)
{
	if (close(pipe) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_redirect_pipes(int **pipes, int read_fd, int write_fd)
{
	int	i;

	i = -1;
	while (pipes[++i])
	{
		if (pipes[i][0] != red_fd)
			if (ft_close(pipes[i][0]))
				return (1);
		if (pipes[i][1] != write_fd)
			if (ft_close(pipes[i][1]))
				return (1);
	}
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

int	ft_dup2_fds(int read_fd, int write_fd)
{
	if (ft_dup2(read_fd, stdin) || ft_dup2(write_fd, stdout))
		return (1);
}

int	ft_execve(char *path, char **comands)
{
	if (execev(path, cmd, NULL)  == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_family_process(int **pipes, char **comands, int i)
{
	int	pid;
	char	*path;
	
	pid = fork();
	if (pid == 0)
	{
		ft_redirect_pipes(pipes, pipes[i][0], pipes[i + 1][1]);
		ft_dup2_files(pipes[i][0], pipes[i + 1][1]);
		path = ft_find_cmd(comands[0]);
		ft_execve(path, comands);
	}
	else
	{
		ft_free_cmd();
	}
}
