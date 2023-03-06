/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:34:12 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 17:09:58 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_check_access(char *path)
{
	if (access(path, F_OK | R_OK))
	{
		ft_printf("❌ %s: ", path);
		perror("");
		return (1);
	}
	return (0);
}

int	ft_open(char *path, int flag)
{
	int	fd;

	fd = open(path, O_CREAT | O_WRONLY | flag, 0660);
	if (fd <= 0)
	{
		perror("");
		return (-1);
	}
	return (fd);
}

int	ft_redirect_output(char *path, int flag)
{
	int	fd;

	fd = ft_open(path, flag);
	if (fd < 0)
	{
		ft_close(STDOUT_FILENO);
		return (1);
	}
	if (ft_dup2(fd, STDOUT_FILENO))
		return (1);
	if (ft_close(fd))
		return (1);
	return (0);
}

static int	ft_open2(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		perror("");
		return (-1);
	}
	return (fd);
}

int	ft_redirect_input(char *path)
{
	int	fd;

	if (ft_check_access(path))
		return (1);
	fd = ft_open2(path);
	if (fd < 0)
		return (1);
	if (ft_dup2(fd, STDIN_FILENO))
		return (1);
	if (ft_close(fd))
		return (1);
	return (0);
}
