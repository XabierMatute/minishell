/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:52:46 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 20:26:38 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_eof(char *entry, char *eof)
{
	char	*aux;

	aux = ft_substr(entry, 0, ft_strlen(entry) - 1);
	if (*aux == '\0')
		return (free(aux), 1);
	if (!ft_strncmp(aux, eof, ft_strlen(eof) + 1))
		return (free(aux), 0);
	free(aux);
	return (1);
}

int	ft_save_entry(int fd, char *eof)
{
	char	*entry;

	entry = 0;
	rl_on_new_line();
	while (g_cp_env)
	{
		entry = readline(">");
		if (ft_atoi(ft_getenv("?")) == 1)
			return (ft_atoi(ft_getenv("?")) == 1);
		if (!entry)
			return (0);
		if (!ft_strncmp(entry, eof, ft_strlen(eof) + 1))
			return (free(entry), 0);
		if (write(fd, entry, ft_strlen(entry)) < 0)
			return (free(entry), 1);
		write(fd, "\n", 1);
		free(entry);
	}
	return (1);
}

int	ft_here_doc(char *eof)
{
	int		pipe[2];

	ft_update_error(0);
	ft_add_redirections_listener();
	if (ft_pipe(pipe))
		return (1);
	if (ft_save_entry(pipe[1], eof))
		return (1 + ft_close(pipe[0]) || ft_close(pipe[1]));
	if (ft_dup2(pipe[0], STDIN_FILENO))
		return (1);
	if (ft_close(pipe[0]) || ft_close(pipe[1]))
		return (1);
	return (0);
}
