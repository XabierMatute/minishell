/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validsintax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:28:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 16:49:34 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	validsintax(char *s)
{
	return (checknoin(s)
		&& checkpipes(s)
		&& checkdiples(s));
}
