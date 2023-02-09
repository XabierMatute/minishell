/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:30:39 by jperez            #+#    #+#             */
/*   Updated: 2023/02/08 19:05:16 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void ft_manage_signals(int signum)
{
	if (signum == SIGQUIT)
	{
	printf("aita");
		rl_redisplay();
	}
	else if (signum == SIGINT)
		ft_sigint_action();
}

int ft_add_parent_listener()
{
	type_sa sa;

	sa.sa_handler = ft_manage_signals;
	ft_manage_terminal(0);
	if (ft_siagction(SIGQUIT, &sa) || ft_siagction(SIGINT, &sa))
		return (1);

	return (0);
}
