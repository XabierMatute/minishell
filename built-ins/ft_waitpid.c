/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:58:50 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/02 16:00:43 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_waitpid(int pid)
{
	int			e;

	waitpid (pid, &e, 0);
	if (WIFEXITED(e))
		ft_update_error(WEXITSTATUS(e));
	else if (WIFSIGNALED(e))
		ft_update_error(WTERMSIG(e) + 128);
}
