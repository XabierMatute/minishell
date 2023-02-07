/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:24:19 by jperez            #+#    #+#             */
/*   Updated: 2023/02/07 18:45:12 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_advance_to_equal(char *variable)
{
	if (!*variable)
		return (NULL);
	while (*variable != '=')
		variable++;
	return (++variable);
}

char *ft_getenv(char *variable)
{
	t_node	*ptr;

	if (G_cp_env->peek)
	{
		ptr = G_cp_env->peek;
		while (ptr)
		{
			if (!ft_strncmp(ptr->variable, variable, ft_strlen(variable)))
				return (ft_advance_to_equal(ptr->variable));
			ptr = ptr->next;
		}
	}
	return (NULL);
}
