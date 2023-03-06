/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:59:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 17:59:19 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	onlychild(char **comands)
{
	pid_t		pid;

	if (!comands)
		return (merror());
	pid = fork();
	if (!pid)
		exit(ft_execve(comands[0], comands));
	ft_free_2d_arr((void **)comands);
	ft_waitpid(pid);
	return (0);
}

static int	nopipes(char *comand)
{
	char	**comands;

	if (makeredirections(comand))
		return (1);
	comands = expandall(ft_split(comand, ' '));
	if (!comands)
		return (merror());
	if (comands[0])
	{
		ft_add_child_listener();
		if (is_builtin(comands))
			ft_update_error(ft_manage_builtins(comands));
		else
			onlychild(ft_copy(comands, ft_find_cmd(comands[0]),
					ft_args_lenght(comands)));
	}
	ft_free_2d_arr((void **)comands);
	return (0);
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
			if (prepcontain(str, '|'))
				pipes(ft_split(str, '|'));
			else
				nopipes(str);
		}
	}
	free(str);
}

int	minishell(void)
{
	int		stdio[2];

	getstdio(stdio);
	while (g_cp_env)
	{
		resetstdio(stdio);
		if (ft_add_father_listener())
			serror();
		processline(readline("minishell: "));
	}
	return (0);
}
