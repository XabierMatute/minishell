/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printexport.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:43:01 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/05 20:29:15 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	printexport(char	*s)
{
	if (!contain(s, '='))
		return (ft_printf("declare -x %s\n", s));
	ft_printf("declare -x ");
	while (*s && *s != '=')
		write(1, s++, 1);
	s++;
	return (ft_printf("=\"%s\"\n", s));
}
