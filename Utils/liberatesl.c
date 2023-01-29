/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberatesl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:00:38 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 17:01:47 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**liberatesl(char ***f, unsigned int p)
{
	unsigned int	i;
	char			**sl;

	i = 0;
	sl = *f;
	while (i < p && sl[i])
	{
		free(sl[i]);
		i++;
	}
	free(sl);
	return (NULL);
}