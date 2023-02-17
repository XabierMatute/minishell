/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_erro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:05:05 by jperez            #+#    #+#             */
/*   Updated: 2023/02/17 17:06:01 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_update_error(int	n)
{
	char	*num;

	num = ft_itoa(n);
	free(G_cp_env->peek->variable);
	G_cp_env->peek->variable = ft_strjoin("?=", num);
	free(num);
}
