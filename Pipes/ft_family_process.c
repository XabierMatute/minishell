/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_family_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:33:51 by jperez            #+#    #+#             */
/*   Updated: 2023/02/17 18:02:29 by xmatute-         ###   ########.fr       */
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


int	ft_family_process(int **pipes, char *comand, int i)
{
	pid_t		pid;
	char	**aux_cmd;
	char	**comands;
	
	// printf("HOLLLLAA\n");

	pid = fork();
	ft_add_child_listener();
	
	if (pid == 0)//yo metia todo esto en una función child process
	{

			
		// printf("----->Son[%d]: %d\n", i, getpid());
		if (ft_choose_dups(pipes, i))
			return (rerror());		
		// redirections(comand);// lo unico gordo que queda ^^
		comands = expandall(ft_split(comand, ' '));
		if (!comands)
			return(10);//mejora esto
		if (comands[0])
		{
			exit(ft_manage_builtins(comands));
			aux_cmd = ft_copy(comands, ft_find_cmd(comands[0]), ft_args_lenght(comands));// lo de comand not found o No such file or directory? btw tiene pinta de que esta linea es demasiado larga para la norma
			if (!aux_cmd)
				exit(-1);//cambiar esto por lo del env?
			ft_free_2d_arr(comands);
			exit(ft_execve(aux_cmd[0], aux_cmd));//hmmmm
		}
	}
	else
	{
		if (pipes)
		{
			/* code */
		}
		
		// if (!pipes)
		// {
		// 	printf("\nadios %i\n", waitpid(-1, NULL, 0));
		// }
		// else if (!pipes[i])
		// 	printf("\nadios %i\n", waitpid(-1, NULL, 0));
		

		// dup2(STDIN_FILENO, 0);
		// dup2(STDOUT_FILENO, 1);
		//ft_free_cmd();
	}
	return (0);
}