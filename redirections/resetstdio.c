/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetstdio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:28:18 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/21 17:32:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*resetstdio(int	stdio[2])
{
	ft_dup2(stdio[0], STDIN_FILENO);
	ft_dup2(stdio[1], STDOUT_FILENO);
	stdio[0] = dup(STDIN_FILENO);
	stdio[1] = dup(STDOUT_FILENO);
	return(stdio);
}