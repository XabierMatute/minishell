/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:20:23 by jperez            #+#    #+#             */
/*   Updated: 2023/02/06 18:50:47 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_siagction(int signal, type_sa *sa)
{
	if (sigaction(signal, sa, NULL) == -1)
    {
        perror("sigaction");
        return (1);
    }
	return (0);
}

void ft_manage_signals(int signum)
{
	printf("Enviada la señal %d\n", signum);
	if (signum == SIGQUIT)
		printf("HOA\n");
	/*
	if (signum == EOF)
	{
		printf("GGGGG\n");
		exit(0);
	}
	*/
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
   		rl_redisplay();
	}
}

int ft_add_listener()
{
	type_sa sa;

	sa.sa_handler = ft_manage_signals;
	if (ft_siagction(SIGQUIT, &sa) || ft_siagction(SIGINT, &sa))
		return (1);

	return (0);
}
