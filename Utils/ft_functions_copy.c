/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:10:30 by jperez            #+#    #+#             */
/*   Updated: 2023/02/09 18:09:07 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_execve(char *path, char **comands)
{
	if (execve(path, comands, NULL)  == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}
 
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

int	ft_siagction(int signal, type_sa *sa)
{
	if (sigaction(signal, sa, NULL) == -1)
    {
        perror("sigaction");
        return (1);
    }
	return (0);
}
