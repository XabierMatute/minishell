/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:23:49 by jperez            #+#    #+#             */
/*   Updated: 2023/02/07 20:54:03 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_stack	*ft_create_env(char **env)
{
	int		i;

	G_cp_env = ft_create_stack(); 
	if (!env)
		return (NULL);
	i = -1;
	while (env[++i])
		ft_push(G_cp_env, ft_strdup(env[i]));
	return (G_cp_env);
	printf("HOLA\n");
}
