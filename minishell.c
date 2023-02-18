/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:59:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/18 13:15:15 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

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
static int onlychild(char **comands)
{
	pid_t		pid;
	int			e;

	e = 0;	
	if (!comands)
		return(merror());
	pid = fork();
	if	(!pid)
		exit(ft_execve(comands[0], comands));
	ft_free_2d_arr(comands);
	waitpid (pid, &e, 0);
	ft_update_error(WEXITSTATUS(e));
}
static int nopipes(char *comand)
{
	char	**comands;

	// redirections(comand);
	comands = expandall(ft_split(comand, ' '));
	if (!comands)
		return(merror());
	if (comands[0])
	{
		if (is_builtin(comands))
			ft_update_error(ft_manage_builtins(comands));//hay que añadirlo a $?
		else
			onlychild(ft_copy(comands, ft_find_cmd(comands[0]), ft_args_lenght(comands)));
		ft_free_2d_arr(comands);
	}
}

static void	processline(char *str)
{
	if (str == NULL)
		ft_exit(NULL);
	if (*str != '\0')
	{
		add_history(str);
		if (validsintax(str))
		{
			if (contain(str, '|'))
				pipes(ft_split(str, '|'));
			else
				nopipes(str);
		}
	}
	free(str);
}


int	minishell(void)
{
	char	*str;

	str = NULL;
	while (G_cp_env)
	{
		if(ft_add_father_listener())
			serror();
		processline(readline("minishell: "));
	}
	return (0);
}
