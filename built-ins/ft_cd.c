/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:27 by jperez            #+#    #+#             */
/*   Updated: 2023/02/09 18:47:46 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_check_access(char *path)
{
	printf("%s\n", path);
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
	/*
	if (lenght > 1)
	{
		ft_printf("❌ cd: string not in pwd %s\n", args[0]);
		return (1);
	}
	*/
	if (lenght == 0)
		return (1);
	return (0);
}

void	ft_cd(char **args)
{
	if (ft_check_cd_args(args))
		return ;
	if (!ft_check_access(args[1]))
		chdir(args[1]);
}

