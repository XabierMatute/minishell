/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:52:46 by jperez            #+#    #+#             */
/*   Updated: 2023/03/07 11:34:53 by jperez           ###   ########.fr       */
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


//int	ft_here_doc(char *eof)
int		ft_here_doc(char **eof, int i)
{
	static int	process;
	static int	cp_stdin;
	static int	lap;
	//int			aux;
	int			pipe[2];

	printf("----->ENTRAAA\n");;

	if (!process || process == NO_STARTED)
	{
		printf("Primera buelta\n");
		printf("Lats cp_stdin: %d\n", cp_stdin);
		cp_stdin = dup(STDIN_FILENO);
		printf("New cp_stdin: %d\n", cp_stdin);
		if (eof[i + 1] == NULL)
		{
			printf("Ultima buelta\n");
			lap = END;
		}
		else
			lap = START;
	}
	else 
	{
		printf("buelta N\n");
		printf("Last cp_stdin: %d\n", cp_stdin);
		close(STDIN_FILENO);
		cp_stdin = dup(cp_stdin);//Aqui ns donde hay que cerrar algun fd, para q no se acumulen
		cp_stdin = dup(cp_stdin);
		dup2(STDIN_FILENO, cp_stdin);
		printf("New cp_stdin 2: %d\n", cp_stdin);
		if (lap == MIDDLE)
			cp_stdin = dup(cp_stdin);
		printf("Middle cp_stdin 3: %d\n", cp_stdin);
		if (eof[i + 1] == NULL)
		{
			printf("Ultima buelta\n");
			lap = END;
		}
		else
			lap = MIDDLE;
	}


	ft_update_error(0);
	ft_add_redirections_listener();
	if (ft_pipe(pipe))
		return (1);
	if (ft_save_entry(pipe[1], eof[i]))
		return (1 + ft_close(pipe[0]) || ft_close(pipe[1]));
	if (ft_dup2(pipe[0], STDIN_FILENO))
		return (1);
	if (ft_close(pipe[0]) || ft_close(pipe[1]))
		return (1);

	if (lap == START)
	{
		printf("Continue...\n");
		process = STARTED;
	}
	else if (lap == MIDDLE)
	{
		printf("in process..\n");
		process = STARTED;
	}
	else if (lap == END)
	{
		printf("FInished\n");
		process = NO_STARTED;
		close(cp_stdin); //Ns si funciona ifgaul rompe el STDIN
	}
	printf("------------------\n");
	return (0);
}
