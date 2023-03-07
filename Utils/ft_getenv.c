/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:24:19 by jperez            #+#    #+#             */
/*   Updated: 2023/03/07 19:50:32 by jperez           ###   ########.fr       */
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

char	*ft_getenv(char *variable)
{
	t_node	*ptr;

	if (g_cp_env->peek)
	{
		ptr = g_cp_env->peek;
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

t_node	*ft_export_equal(char *variable, t_node *ptr)
{
	if (contain(ptr->variable, '=') && !ft_strncmp(variable, ptr->variable, \
		ft_vlen(ptr->variable) + 1))
		return (ptr);
	if (!contain(ptr->variable, '=') && !ft_strncmp(variable, ptr->variable, \
		ft_vlen(variable)) && ft_vlen(variable) == ft_strlen(ptr->variable))
		return (ptr);
	return (NULL);
}

t_node	*ft_export_no_equal(char *variable, t_node *ptr)
{
	if (contain(ptr->variable, '=') && !ft_strncmp(variable, ptr->variable, \
		ft_vlen(ptr->variable)) && \
		ft_strlen(variable) == ft_vlen(ptr->variable))
		return (ptr);
	if (!contain(ptr->variable, '=') && !ft_strncmp(variable, ptr->variable, \
		ft_strlen(variable) + 1))
		return (ptr);
	return (NULL);
}

t_node	*ft_getenv_node(char *variable)
{
	t_node	*ptr;
	t_node	*output;

	output = NULL;
	if (g_cp_env->peek)
	{
		ptr = g_cp_env->peek;
		while (ptr)
		{
			if (contain(variable, '='))
				output = ft_export_equal(variable, ptr);
			else
				output = ft_export_no_equal(variable, ptr);
			if (!output)
				ptr = ptr->next;
			else
				return (output);
		}
	}
	return (NULL);
}
