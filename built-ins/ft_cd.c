/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:27 by jperez            #+#    #+#             */
/*   Updated: 2023/01/29 17:49:45 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_check_access(char *path)
{
	if (access(path, F_OK | R_OK))
	{
		ft_printf("%s: ", path);
		perror("");
		return (1);
	}
	return (0);
}

void	ft_cd(char *path)
{
	if (!ft_check_access(path))
		chdir(path);
}

