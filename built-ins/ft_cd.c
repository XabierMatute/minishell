/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:27 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 16:43:20 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_chdir(char *path)
{
	if (chdir(path) != 0)
	{
		ft_printf("❌ %s: ", path);
		perror("");
		return (1);
	}
	return (0);
}

void	ft_replace_oldpwd(t_node *node, char *new_old_pwd)
{
	if (!node)
		return ;
	if (ft_strncmp(node->variable + 7, new_old_pwd, ft_strlen(node->variable)))
	{
		free(node->variable);
		node->variable = ft_strjoin("OLDPWD=", new_old_pwd);
	}
	free(new_old_pwd);
}

void	ft_replace_pwd(t_node *node, char *new_pwd)
{
	if (!node)
		return ;
	if (ft_strncmp(node->variable + 4, new_pwd, ft_strlen(node->variable)))
	{
		free(node->variable);
		node->variable = ft_strjoin("PWD=", new_pwd);
	}
	free(new_pwd);
}

int	ft_go_to(char *old_pwd, char *path)
{
	if (chdir(ft_getenv(path)) != 0)
	{
		ft_printf("❌ %s has gone to sleep\n", path);
		return (1);
	}
	if (!ft_strncmp(path, "OLDPWD\0", 7))
		ft_pwd(0);
	ft_replace_oldpwd(ft_getenv_node("OLDPWD"), old_pwd);
	ft_replace_pwd(ft_getenv_node("PWD"), ft_getpwd());
	return (0);
}

int	ft_cd(char **args)
{
	char	*old_pwd;

	old_pwd = ft_getpwd();
	if (!*args || !ft_strncmp(*args, "~\0", 2))
		return (ft_go_to(old_pwd, "HOME"));
	else if (!ft_strncmp(*args, "-\0", 2))
		return (ft_go_to(old_pwd, "OLDPWD"));
	else
	{
		if (ft_chdir(*args))
			return (1);
		ft_replace_oldpwd(ft_getenv_node("OLDPWD"), old_pwd);
		ft_replace_pwd(ft_getenv_node("PWD"), ft_getpwd());
	}
	return (0);
}
