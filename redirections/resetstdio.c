/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetstdio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:28:18 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 19:01:15 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*resetstdio(int stdio[2])
{
	ft_dup2(stdio[0], STDIN_FILENO);
	ft_dup2(stdio[1], STDOUT_FILENO);
	return (stdio);
}
