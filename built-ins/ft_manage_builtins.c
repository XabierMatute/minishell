/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:33:20 by jperez            #+#    #+#             */
/*   Updated: 2023/02/10 17:33:06 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_manage_builtins(char *str)
{
	if (!strncmp(str, "echo", 4))
	{
		ft_echo(ft_split(str, ' ') + 1);
		return (1);
	}
	else if (!strncmp(str, "cd", 2))
	{
		ft_cd(ft_split(str, ' ') + 1);
		return (1);
	}
	else if (!strncmp(str, "pwd", 3))
	{
		ft_pwd(ft_split(str, ' ') + 1);
		return (1);
	}
	else if (!strncmp(str, "export", 6))
	{
		ft_export(ft_split(str, ' ') + 1);
		return (1);
	}
	else if (!strncmp(str, "unset", 5))
	{
		ft_unset(ft_split(str, ' ') + 1);
		return (1);
	}
	else if (!strncmp(str, "env", 3))
	{
		ft_env(ft_split(str, ' ') + 1);
		return (1);
	}
	return (0);
}
