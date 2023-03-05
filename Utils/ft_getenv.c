/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:24:19 by jperez            #+#    #+#             */
/*   Updated: 2023/03/05 19:57:45 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	ft_vlen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != '=')
		l++;
	return (l);
}

char	*ft_advance_to_equal(char *variable)
{
	if (!*variable)
		return (NULL);
	while (*variable != '=')
		variable++;
	return (++variable);
}

char	*ft_getenv(char *variable)
{
	t_node	*ptr;

	if (G_cp_env->peek)
	{
		ptr = G_cp_env->peek;
		while (ptr)
		{
			if (!ft_strncmp(ptr->variable, variable, ft_vlen(ptr->variable)) && \
				contain(ptr->variable, '='))
				return (ft_advance_to_equal(ptr->variable));
			ptr = ptr->next;
		}
	}
	return (NULL);
}

t_node	*ft_getenv_node(char *variable)
{
	t_node	*ptr;

	if (G_cp_env->peek)
	{
		ptr = G_cp_env->peek;
		while (ptr)
		{
			if (!ft_strncmp(ptr->variable, variable, ft_vlen(ptr->variable)) && \
				contain(ptr->variable, '='))
				return (ptr);
			ptr = ptr->next;
		}
	}
	return (NULL);
}
