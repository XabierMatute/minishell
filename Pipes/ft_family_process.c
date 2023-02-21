/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_family_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:33:51 by jperez            #+#    #+#             */
/*   Updated: 2023/02/21 17:49:37 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char **ft_copy(char **comands, char *path, int comands_len)
{
	char	**output;
	int		i;
	int		j;

	if (!path)
		return (NULL);
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
	free(path);
	output[i] = NULL;
	return (output);
}

int	ft_choose_dups(int **pipes, int i)
{
	if (!pipes)
		return (0);
	if (i == 0)
		return (ft_dup2_fds(pipes, STDIN_FILENO, pipes[0][1]));
	else if (!pipes[i])
		return (ft_dup2_fds(pipes, pipes[i - 1][0], STDOUT_FILENO));
	else
		return (ft_dup2_fds(pipes, pipes[i - 1][0], pipes[i][1]));
}

void	ex(char **comands)
{
	if (!comands)
		exit(merror());
	exit(ft_execve(comands[0], comands));
}

void	ft_child_process(int **pipes, char *comand, int i)
{
	char	**comands;

	if (ft_choose_dups(pipes, i))
		exit (rerror());
	makeredirections(comand);
	comands = expandall(ft_split(comand, ' '));
	if (!comands)
		exit(merror());
	if (is_builtin(comands))
		exit(ft_manage_builtins(comands));
	ex(ft_copy(comands, ft_find_cmd(comands[0]), ft_args_lenght(comands)));
	ft_free_2d_arr((void **)comands);
}

int	ft_family_process(int **pipes, char *comand, int i)
{
	pid_t		pid;
	
	// printf("HOLLLLAA\n");

	pid = fork();
	if (pid < 0)
		perror("");	
	ft_add_child_listener();
	if (pid == 0)//yo metia todo esto en una función child process
		ft_child_process(pipes, comand, i);
	else
	{
		
	}
	return (0);
}