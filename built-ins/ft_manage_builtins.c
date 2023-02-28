/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:33:20 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 16:58:43 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char **comands)
{
	if (!*comands)
		return (1);
	else if (!ft_strncmp(comands[0], "echo\0", 5))
		return (1);
	else if (!ft_strncmp(comands[0], "cd\0", 3))
		return (1);
	else if (!ft_strncmp(comands[0], "pwd\0", 4))
		return (1);
	else if (!ft_strncmp(comands[0], "export\0", 7))
		return (1);
	else if (!ft_strncmp(comands[0], "unset\0", 6))
		return (1);
	else if (!ft_strncmp(comands[0], "env\0", 4))
		return (1);
	else if (!ft_strncmp(comands[0], "exit\0", 5))
		return (1);
	return (0);
}

int	ft_manage_builtins(char **comands)
{
	if (!*comands)
		return (1);
	else if (!ft_strncmp(comands[0], "echo\0", 5))
		return (ft_echo(comands + 1));
	else if (!ft_strncmp(comands[0], "cd\0", 3))
		return (ft_cd(comands + 1));
	else if (!ft_strncmp(comands[0], "pwd\0", 4))
		return (ft_pwd(comands + 1));
	else if (!ft_strncmp(comands[0], "export\0", 7))
		return (ft_export(comands + 1));
	else if (!ft_strncmp(comands[0], "unset\0", 6))
		return (ft_unset(comands + 1));
	else if (!ft_strncmp(comands[0], "env\0", 4))
		return (ft_env(comands + 1));
	else if (!ft_strncmp(comands[0], "exit\0", 5))
		return (ft_exit(comands + 1));
	return (0);
}
