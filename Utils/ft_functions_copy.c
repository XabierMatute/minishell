/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:10:30 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 18:02:08 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_close(int pipe)
{
	if (close(pipe) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_pipe(int *fds)
{
	if (pipe(fds) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	ft_siagction(int signal, t_type_sa *sa)
{
	if (sigaction(signal, sa, NULL) == -1)
	{
		perror("sigaction");
		return (1);
	}
	return (0);
}
