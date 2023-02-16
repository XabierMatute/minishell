/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:11:41 by jperez            #+#    #+#             */
/*   Updated: 2023/02/15 17:31:20 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **ft_transform_env(void)
{
	int		i;
	t_node	*ptr;
	char	**env;

	env = (char **)malloc(sizeof(char *) * G_cp_env->len);
	i = 0;
	ptr = G_cp_env->peek;
	while (ptr)
	{
		if (ft_strncmp(ptr->variable, "?", 1))
			env[i++] = ft_strdup(ptr->variable);
		ptr = ptr->next;
	}
	env[i] = NULL;
	return (env);
}
