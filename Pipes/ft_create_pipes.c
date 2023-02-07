/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:07:35 by jperez            #+#    #+#             */
/*   Updated: 2023/02/07 15:26:19 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pipe(int *fds)
{
	if (pipe(fds) == -1)
	{
		perror("");
		return (1);
	}
	return (0);
}

int	**ft_create_pipes(int pipes_num)
{
	int		i;
	char	**pipes;
	
	pipes = (int **)malloc(sizeof(int *) * (pipes_num + 1));
	if (!pipes)
		return (NULL);
	i = -1;
	while (++i < pipes_num)
	{
		pipes[i] = (int *)malloc(sizeof(int *) * 2);
		if (!pipes[i])
			return (NULL);
		if (ft_pipe(pipes[i]))
			return (NULL);
	}
	pipes[i] = NULL;
	return (pipes);
}
