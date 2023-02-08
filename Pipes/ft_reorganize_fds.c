/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reorganize_fds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:26:14 by jperez            #+#    #+#             */
/*   Updated: 2023/02/08 17:26:35 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_close_pipes(int **pipes, int read_fd, int write_fd)
{
	int	i;

	i = -1;
	while (pipes[++i])
	{
		if (pipes[i][0] != read_fd)
			if (ft_close(pipes[i][0]))
				return (1);
		if (pipes[i][1] != write_fd)
			if (ft_close(pipes[i][1]))
				return (1);
	}
	return (0);
}

int	ft_dup2_fds(int read_fd, int write_fd)
{
	if (ft_dup2(read_fd, 0) || ft_dup2(write_fd, 1))
		return (1);
	return (0);
}
