/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:05:05 by jperez            #+#    #+#             */
/*   Updated: 2023/02/17 17:54:51 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_error(int	n)
{
	char	*num;

	num = ft_itoa(n);
	if (!num)
		merror();
	free(G_cp_env->peek->variable);
	G_cp_env->peek->variable = ft_strjoin("?=", num);
	free(num);
}
