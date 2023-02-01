/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:23:49 by jperez            #+#    #+#             */
/*   Updated: 2023/02/01 18:51:47 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_stack	*ft_create_env(char **env, t_stack *cp_env)
{
	int		i;

	if (!env)
		return (NULL);
	i = -1;
	while (env[++i])
		ft_push(cp_env, ft_strdup(env[i]));
	return (cp_env);
}
