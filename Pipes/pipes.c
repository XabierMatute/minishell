/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:04:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/01 19:49:40 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void pipes(char **comands)
{
	int	i;
	int	**p;

	if (!comands)
	{
		ft_printf("⚠️Error de memoria\n");
		return ;
	}
	i = 0;
	p = createpipes(ft_args_lenght(comands));
	pipe(comands[i], 0, p[i][1]);
	i++;
		while (comands[i + 1])
		{
			pipe(comands[i], p[i][0], p[i + 1][1]);
		}
	liberatesl(&comands, 4294967295);
}
