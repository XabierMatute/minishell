/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:23:49 by jperez            #+#    #+#             */
/*   Updated: 2023/02/11 19:45:38 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_stack	*ft_create_env(char **env)
{
	int		i;

	if (!env)
		return (NULL);
	G_cp_env = ft_create_stack(); 
	if (!G_cp_env)
		return (NULL);
	ft_push(G_cp_env, ft_strdup("?=0"));
	i = -1;
	while (env[++i])
		ft_push(G_cp_env, ft_strdup(env[i]));
	return (G_cp_env);
	printf("HOLA\n");
}
