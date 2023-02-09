/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:30:39 by jperez            #+#    #+#             */
/*   Updated: 2023/02/09 18:13:46 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_manage_terminal() {
  struct termios tty;
  tcgetattr(STDIN_FILENO, &tty);
  tty.c_lflag &= ~ECHOCTL;
  tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void	ft_sigint_action()
{
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line("", 1);
   		rl_redisplay();
}

static	void ft_manage_signals(int signum)
{
	if (signum == SIGQUIT)
		rl_redisplay();
	else if (signum == SIGINT)
		ft_sigint_action();
}

int ft_add_father_listener()
{
	type_sa sa;

	sa.sa_handler = ft_manage_signals;
	sa.sa_flags = SA_RESTART;
	ft_manage_terminal();
	if (ft_siagction(SIGQUIT, &sa) || ft_siagction(SIGINT, &sa))
		return (1);

	return (0);
}

