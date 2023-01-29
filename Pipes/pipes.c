/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:04:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 19:29:32 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void pipes(char **comands)
{
	if (!comands)
	{
		ft_printf("⚠️Error de memoria");
		return ;
	}
	liberatesl(&comands, 4294967295);
}
