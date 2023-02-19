/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:52:46 by jperez            #+#    #+#             */
/*   Updated: 2023/02/19 18:45:07 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_eof(char *entry, char *eof)
{
	char	*aux;

	aux = ft_substr(entry, 0, ft_strlen(entry) - 1);
	printf("%s", aux);
	if (*aux == '\0')
		return (free(aux), 1);
	if (!ft_strncmp(aux, eof, ft_strlen(aux)))
		return (free(aux), 0);
	free(aux);
	return (1);
}

void	ft_save_entry(int fd, char *eof)
{
	char	*entry;

	while (1)
	{
		entry = ft_get_next_line(0);
		if (!ft_check_eof(entry, eof))
		{
			free(entry);
			break;
		}
		write(fd, entry, ft_strlen(entry) - 1);
		write(fd, "\n", 1);
		free(entry);
	}
}

int	ft_here_doc(char *eof)
{
	int		pipe[2];

	if (ft_pipe(pipe))
		return (1);
	ft_save_entry(pipe[1], eof);
	if (ft_dup2(pipe[0], STDIN_FILENO))
		return (1);
	if (ft_close(pipe[0]) || ft_close(pipe[1]))
		return (1);
	return (0);
}
