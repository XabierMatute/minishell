/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections_signals.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:11:12 by jperez            #+#    #+#             */
/*   Updated: 2023/03/05 18:56:37 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
static void	ft_manage_terminal() {
  struct termios tty;
  tcgetattr(STDIN_FILENO, &tty);
  tty.c_lflag |= ECHOCTL;
  tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
*/
/*
static void	ft_sigint_action2(void)
{
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line(">>", 1);
   		rl_redisplay();
}
*/

void	ft_empty_pipe(int fd)
{
//	int		bytes;
	//char	c[2];

	fd  = 1;
	/*
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, c, 1);
		c[bytes] = '\0';
	}
	*/
	ft_update_error(1);
}

void ft_manage_here_doc_signals(int signum)
{
	static int	fd;

	if (signum == SIGQUIT)
		return (rl_redisplay());
	else if (signum == SIGINT)
		ft_empty_pipe(fd);
	fd = 1;
	if (signum < 0)
		fd = 0 - signum;
}

int ft_add_redirections_listener()
{
	type_sa sa;

	sa.sa_sigaction = 0;
	sa.sa_mask = 0;
	sa.sa_handler = ft_manage_here_doc_signals;
	sa.sa_flags = SA_RESTART;
	//ft_manage_terminal();
	if (ft_siagction(SIGQUIT, &sa) || ft_siagction(SIGINT, &sa))
		return (1);
	return (0);
}
