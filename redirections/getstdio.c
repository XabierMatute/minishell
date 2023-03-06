/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:19:19 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 17:14:50 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*getstdio(int stdio[2])
{
	stdio[0] = dup(STDIN_FILENO);
	stdio[1] = dup(STDOUT_FILENO);
	return (stdio);
}
