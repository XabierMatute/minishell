/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:20:11 by jperez            #+#    #+#             */
/*   Updated: 2023/02/10 17:25:05 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strisalnum(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isalnum(str[i]))
			return (0);
	return (1);
}
