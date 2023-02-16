/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:27 by jperez            #+#    #+#             */
/*   Updated: 2023/02/16 14:41:51 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

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

/*
int		ft_check_cd_args(char **args)
{
	int	lenght;

	lenght =ft_args_lenght(args);
	if (lenght == 0)
		return (1);
	return (0);
}
*/

int	ft_cd(char **args)
{
	if (!*args)
		chdir(ft_getenv("HOME"));
	else
	{
		if (!ft_check_access(args[0]))
			chdir(args[0]);
	}
	return(55);
}

