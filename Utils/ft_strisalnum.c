/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:20:11 by jperez            #+#    #+#             */
/*   Updated: 2023/02/16 16:01:12 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strisalnum(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(ft_isalnum(str[i]) || str[i] == '='))
			return (0);
	return (1);
}
