/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections_signals.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:11:12 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 18:02:08 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_manage_here_doc_signals(int signum)
{
	if (signum == SIGINT)
	{
		ft_update_error(1);
		close(STDIN_FILENO);
	}
}

int	ft_add_redirections_listener(void)
{
	t_type_sa	sa;

	sa.sa_sigaction = 0;
	sa.sa_mask = 0;
	sa.sa_handler = ft_manage_here_doc_signals;
	sa.sa_flags = SA_RESTART;
	if (ft_siagction(SIGQUIT, &sa) || ft_siagction(SIGINT, &sa))
		return (1);
	return (0);
}
