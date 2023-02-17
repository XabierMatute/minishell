/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:27 by jperez            #+#    #+#             */
/*   Updated: 2023/02/17 17:26:22 by jperez           ###   ########.fr       */
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

int	ft_go_home()
{
	if (chdir(ft_getenv("HOME")) != 0)
	{
		ft_printf("❌ HOME has gone to sleep\n");
		return (1);
	}
	return (0);
}

int	ft_cd(char **args)
{
	if (!*args)
		return (ft_go_home());
	else
	{
		if (chdir(args[0]) != 0)
		{
			ft_printf("❌ %s: ", args[0]);
			perror("");
			return (1);
		}
	}
	return(0);
}
