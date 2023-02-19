/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:27 by jperez            #+#    #+#             */
/*   Updated: 2023/02/19 18:03:01 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

/*
int	ft_check_access(char *path)
{
	printf("---->%s\n", path);
	if (access(path, F_OK | R_OK))
	{
		ft_printf("❌ %s: ", path);
		perror("");
		return (1);
	}
	return (0);
}

int		ft_check_cd_args(char **args)
{
	int	lenght;

	lenght =ft_args_lenght(args);
	if (lenght == 0)
		return (1);
	return (0);
}
*/

void	ft_replace_oldpwd(t_node *node, char *new_old_pwd)
{
	if (ft_strncmp(node->variable + 7, new_old_pwd, ft_strlen(node->variable)))
	{
		free(node->variable);
		node->variable = ft_strjoin("OLDPWD=", new_old_pwd);
	}
	free(new_old_pwd);
}

void	ft_replace_pwd(t_node *node, char *new_pwd)
{
	if (ft_strncmp(node->variable + 4, new_pwd, ft_strlen(node->variable)))
	{
		free(node->variable);
		node->variable = ft_strjoin("PWD=", new_pwd);
	}
	free(new_pwd);
}

int	ft_go_home(char *old_pwd)
{
	if (chdir(ft_getenv("HOME")) != 0)
	{
		ft_printf("❌ HOME has gone to sleep\n");
		return (1);
	}
	ft_replace_oldpwd(ft_getenv_variable("OLDPWD"), old_pwd);
	ft_replace_pwd(ft_getenv_variable("PWD"), ft_getpwd());
	return (0);
}

int	ft_cd(char **args)
{
	char	*old_pwd;

	old_pwd = ft_getpwd();
	if (!*args)
		return (ft_go_home(old_pwd));
	else
	{
		if (chdir(args[0]) != 0)
		{
			ft_printf("❌ %s: ", args[0]);
			perror("");
			free(old_pwd);
			return (1);
		}
		ft_replace_oldpwd(ft_getenv_variable("OLDPWD"), old_pwd);
		ft_replace_pwd(ft_getenv_variable("PWD"), ft_getpwd());
	}
	return(0);
}
