/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_family_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:33:51 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 18:43:59 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	if (makeredirections(comand))
		exit(1);
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

	pid = fork();
	if (pid < 0)
		perror("");
	ft_add_child_listener();
	if (pid == 0)
		ft_child_process(pipes, comand, i);
	return (0);
}
