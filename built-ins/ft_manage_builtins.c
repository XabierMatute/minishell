/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:33:20 by jperez            #+#    #+#             */
/*   Updated: 2023/02/15 18:06:08 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_manage_builtins(char **comands)//apañar lo de como le llega la entrada
{
	if (!ft_strncmp(comands[0], "echo", ft_strlen(comands[0])))//probar a poner echooooo
	{
		ft_echo(comands + 1);
		return (1);
	}
	else if (!ft_strncmp(comands[0], "cd", ft_strlen(comands[0])))
	{
		ft_cd(comands + 1);
		return (1);
	}
	else if (!ft_strncmp(comands[0], "pwd", ft_strlen(comands[0])))
	{
		ft_pwd(comands + 1);
		return (1);
	}
	else if (!ft_strncmp(comands[0], "export", ft_strlen(comands[0])))
	{
		ft_export(comands + 1);
		return (1);
	}
	else if (!ft_strncmp(comands[0], "unset", ft_strlen(comands[0])))
	{
		ft_unset(comands + 1);
		return (1);
	}
	else if (!ft_strncmp(comands[0], "env", ft_strlen(comands[0])))
	{
		ft_env(comands + 1);
		return (1);//poner todos enel return para aorra lineas
	}
	return (0);
}
