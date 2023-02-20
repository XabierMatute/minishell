/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:09:40 by jperez            #+#    #+#             */
/*   Updated: 2023/02/20 16:52:28 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_check_variable(char *variable)
{
	int equal_pos;

	equal_pos = ft_strchr(variable, '=') - variable;
	if (equal_pos == 0 || !ft_strisalnum(variable))
	{
		ft_printf("❌ export: '%s': not a variable identifier\n", variable);
		return (1);
	}
	else if (equal_pos < 0)
	{
		ft_printf("❌ export: intruduce a '=' to export a variable\n");
		return (1);
	}
	return (0);
}

static int	ft_update_variable(char *variable)
{
	t_node	*node;

	node = ft_getenv_node(variable);
	if (!node)
		return (1);
	free(node->variable);
	node->variable = ft_strdup(variable);
	return (0);
}

int	ft_export(char **variables)
{
	int	i;
	int	output;

	output = 0;
	i = -1;
	while (variables[++i])
	{
		if (!ft_check_variable(variables[i]))
		{
			if (ft_update_variable(variables[i]))
				ft_push(G_cp_env, ft_strdup(variables[i]));
		}
		else
			output = 1;
	}
	return (output);
}
