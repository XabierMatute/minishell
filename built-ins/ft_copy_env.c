/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:23:49 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 17:59:19 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_stack	*ft_create_env(char **env)
{
	int		i;

	if (!env)
		return (NULL);
	g_cp_env = ft_create_stack();
	if (!g_cp_env)
		return (NULL);
	ft_push(g_cp_env, ft_strdup("?=0"));
	i = -1;
	while (env[++i])
		ft_push(g_cp_env, ft_strdup(env[i]));
	return (g_cp_env);
}
