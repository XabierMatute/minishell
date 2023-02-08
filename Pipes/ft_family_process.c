/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjust_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:33:51 by jperez            #+#    #+#             */
/*   Updated: 2023/02/08 17:21:07 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_redirect_pipes(int **pipes, int read_fd, int write_fd)
{
	int	i;

	i = -1;
	while (pipes[++i])
	{
		if (pipes[i][0] != read_fd)
			if (ft_close(pipes[i][0]))
				return (1);
		if (pipes[i][1] != write_fd)
			if (ft_close(pipes[i][1]))
				return (1);
	}
	return (0);
}

int	ft_dup2_fds(int read_fd, int write_fd)
{
	if (ft_dup2(read_fd, 0) || ft_dup2(write_fd, 1))
		return (1);
	return (0);
}

char **ft_copy(char **comands, char *path, int comands_len)
{
	char	**output;
	int		i;
	int		j;

	output = (char **)malloc(sizeof(char *) * (comands_len + 1));
	if (!output)
		return (NULL);
	output[0] = ft_strdup(path);
	j = 1;
	i = 0;
	while(comands[++i])
	{
		if (ft_strncmp(comands[i], comands[0], ft_strlen(comands[0])))
		{
			output[j] = ft_strdup(comands[i]);
			j++;
		}

	}
	output[i] = NULL;
	i = -1;
	return (output);
}

int	ft_family_process(int **pipes, char **comands, int i)
{
	int		pid;
	char	**aux_cmd;
	
	pid = fork();
	if (pid == 0)
	{
		//ft_redirect_pipes(pipes, pipes[i][0], pipes[i + 1][1]);
		//ft_redirect_pipes(pipes, NULL, NULL);
		//ft_dup2_fds(pipes[i][0], pipes[i + 1][1]);
		aux_cmd = ft_copy(comands, ft_find_cmd(comands[0]), ft_args_lenght(comands));
		ft_execve(aux_cmd[0], aux_cmd);
	}
	else
	{
		waitpid(pid, NULL, 0);
		//ft_free_cmd();
	}
	return (0);
}
