/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:30:42 by jperez            #+#    #+#             */
/*   Updated: 2023/02/08 19:03:35 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void ft_manage_signals(int signum)
{
	if (signum == SIGQUIT)
	{
		printf("aaaaa");
		write(1, "Quit: 3\n", 10);
		rl_redisplay();
	}
	else if (signum == SIGINT)
	{
		ft_printf("LLOLOL\n");
		ft_sigint_action();
	}
}

int ft_add_child_listener()
{
	type_sa sa;

	sa.sa_handler = ft_manage_signals;
	ft_manage_terminal(1);
	if (ft_siagction(SIGQUIT, &sa) || ft_siagction(SIGINT, &sa))
		return (1);
	return (0);
}
