/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reorganize_fds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:26:14 by jperez            #+#    #+#             */
/*   Updated: 2023/02/14 13:22:03 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	ft_close_pipes(int **pipes, int read_fd, int write_fd)
// {
// 	int	i;

// 	i = -1;
// 	while (pipes[++i])
// 	{
// 		if (pipes[i][0] != read_fd)
// 			if (ft_close(pipes[i][0]))
// 				return (1);
// 		if (pipes[i][1] != write_fd)
// 			if (ft_close(pipes[i][1]))
// 				return (1);
// 	}
// 	// if (STDIN_FILENO != read_fd)
// 	// 	if (ft_close(STDIN_FILENO))
// 	// 		return (1);
// 	// if (STDOUT_FILENO != write_fd)
// 	// 	if (ft_close(STDOUT_FILENO))
// 	// 		return (1);
// 			printf ("hola %i %i\n", read_fd, write_fd);
// 	return (0);
// }

// int	ft_dup2_fds(int **pipes, int read_fd, int write_fd)
// {
// 	if (ft_close_pipes(pipes, read_fd, write_fd))
// 		return (1);
// 	if (ft_dup2(read_fd, 0) || ft_dup2(write_fd, 1))
// 		return (1);
// 	if (ft_close(read_fd) || ft_close(write_fd))
// 		return (1);
// 	return (0);
// }

int	ft_close_pipes(int **pipes, int read_fd, int write_fd)
{
	int	i;

	i = -1;
	if (STDIN_FILENO != read_fd)
		if (ft_close(STDIN_FILENO))
			return (1);

	if (STDOUT_FILENO != write_fd)
		if (ft_close(STDOUT_FILENO))
			return (1);

	while (pipes[++i])
	{
		if (pipes[i][0] == read_fd)
			if (ft_dup2(read_fd, 0))
				return (1);
		if (ft_close(pipes[i][0]))
				return (1);
		if (pipes[i][1] == write_fd)
			if (ft_dup2(write_fd, 1))
				return (1);
		if (ft_close(pipes[i][1]))
				return (1);
	}
	// if (STDIN_FILENO != read_fd)
	// 	if (ft_close(STDIN_FILENO))
	// 		return (1);
	// if (STDOUT_FILENO != write_fd)
	// 	if (ft_close(STDOUT_FILENO))
	// 		return (1);
	// 		printf ("hola %i %i\n", read_fd, write_fd);
	return (0);
}

int	ft_dup2_fds(int **pipes, int read_fd, int write_fd)
{
	if (ft_close_pipes(pipes, read_fd, write_fd))
		return (1);
	// if (ft_dup2(read_fd, 0) || ft_dup2(write_fd, 1))
	// 	return (1);
	// if (ft_close(read_fd) || ft_close(write_fd))
	// 	return (1);
	return (0);
}