/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:31:33 by jperez            #+#    #+#             */
/*   Updated: 2023/03/07 19:49:03 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_check_variable(char *variable)
{
	int	i;

	i = -1;
	while (variable[++i])
	{
		if (!(ft_isalnum(variable[i]) || variable[i] == '_') || \
			ft_isdigit(variable[0]))
		{
			ft_printf("❌ export: '%s': not a variable identifier\n", variable);
			return (1);
		}
	}
	return (0);
}

int	ft_find_variable(t_stack *cp_env, char *variable)
{
	int		i;
	t_node	*ptr;

	i = 0;
	ptr = cp_env->peek;
	while (ptr)
	{
		if (contain(ptr->variable, '=') && !ft_strncmp(ptr->variable, variable, \
			ft_vlen(ptr->variable)))
			return (i);
		else if (!contain(ptr->variable, '=') && !ft_strncmp(ptr->variable, \
			variable, ft_strlen(ptr->variable) + 1))
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (-1);
}

void	ft_delete_variable(t_stack *cp_env, char *variable)
{
	int	pos;

	pos = ft_find_variable(cp_env, variable);
	if (pos == -1)
		return ;
	ft_pop(cp_env, pos);
}

int	ft_unset(char **args)
{
	int	i;
	int	output;

	output = 0;
	i = -1;
	while (args[++i])
	{
		if (!ft_check_variable(args[i]))
			ft_delete_variable(g_cp_env, args[i]);
		else
			output = 1;
	}
	return (output);
}
