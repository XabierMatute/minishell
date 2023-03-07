/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:52:46 by jperez            #+#    #+#             */
/*   Updated: 2023/03/07 16:23:35 by jperez           ###   ########.fr       */
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

void	ft_pre_here(int process, int *cp_stdin, int *lap, char *eof)
{
	int	aux;
	int	aux2;

	if (!process || process == NO_STARTED)
	{
		*cp_stdin = dup(STDIN_FILENO);
		if (eof == NULL)
			*lap = END;
		else
			*lap = START;
	}
	else
	{
		close(STDIN_FILENO);
		aux = *cp_stdin;
		*cp_stdin = dup(*cp_stdin);
		*cp_stdin = dup(*cp_stdin);
		aux2 = *cp_stdin;
		dup2(STDIN_FILENO, *cp_stdin);
		close(aux);
		if (eof == NULL)
			*lap = END;
		else
			*lap = MIDDLE;
	}
}

void	ft_post_here(int lap, int *process, int cp_stdin)
{
	if (lap == START)
		*process = STARTED;
	else if (lap == MIDDLE)
		*process = STARTED;
	else if (lap == END)
	{
		*process = NO_STARTED;
		close(cp_stdin);
	}
}

int	ft_here_doc(char **eof, int i)
{
	static int	process;
	static int	cp_stdin;
	static int	lap;
	int			pipe[2];

	ft_pre_here(process, &cp_stdin, &lap, eof[i + 1]);
	ft_manage_here_doc_signals(-cp_stdin);
	ft_update_error(0);
	ft_add_redirections_listener();
	if (ft_pipe(pipe))
		return (1);
	if (ft_save_entry(pipe[1], eof[i]))
	{
		process = NO_STARTED;
		return (close(cp_stdin), 1 + ft_close(pipe[0]) || ft_close(pipe[1]));
	}
	if (ft_dup2(pipe[0], STDIN_FILENO))
		return (1);
	if (ft_close(pipe[0]) || ft_close(pipe[1]))
		return (1);
	ft_post_here(lap, &process, cp_stdin);
	return (0);
}
