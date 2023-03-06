/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:30:42 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 18:11:47 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_manage_terminal(void)
{
	struct termios	tty;

	ft_bzero(&tty, sizeof(tty));
	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

static void	ft_manage_signals(int signum)
{
	if (signum == SIGQUIT)
		write(1, "Quit: 3\n", 8);
	else if (signum == SIGINT)
		write(1, "\n", 1);
}

int	ft_add_child_listener(void)
{
	t_type_sa	sa;

	sa.sa_sigaction = 0;
	sa.sa_mask = 0;
	sa.sa_handler = ft_manage_signals;
	sa.sa_flags = SA_RESTART;
	ft_manage_terminal();
	if (ft_siagction(SIGQUIT, &sa) || ft_siagction(SIGINT, &sa))
		return (1);
	return (0);
}
