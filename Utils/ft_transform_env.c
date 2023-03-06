/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:11:41 by jperez            #+#    #+#             */
/*   Updated: 2023/03/06 17:59:19 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_transform_env(void)
{
	int		i;
	t_node	*ptr;
	char	**env;

	env = (char **)malloc(sizeof(char *) * g_cp_env->len);
	i = 0;
	ptr = g_cp_env->peek;
	while (ptr)
	{
		if (ft_strncmp(ptr->variable, "?", 1))
			env[i++] = ft_strdup(ptr->variable);
		ptr = ptr->next;
	}
	env[i] = NULL;
	return (env);
}
