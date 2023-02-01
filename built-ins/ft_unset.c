/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:31:33 by jperez            #+#    #+#             */
/*   Updated: 2023/02/01 19:36:40 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_find_variable(t_stack *cp_env, char *variable, int lenght)
{
	int		i;
	t_node *ptr;

	i = 0;
	ptr = cp_env->peek;
	while (ptr)
	{
		if (!ft_strncmp(ptr->variable, variable, lenght))
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (-1);
}

void	ft_delete_variable(t_stack *cp_env, char *variable)
{
	int	pos;

	pos = ft_find_variable(cp_env, variable, ft_strlen(variable));
	if (pos == -1)
		return ;
	ft_pop(cp_env, pos);
}

static int	ft_check_variable(char *variable)
{
	if (ft_strchr(variable, '=') - variable >= 0)
	{
		ft_printf("❌ unset: '%s': not a valid identifier\n", variable);
		return (1);
	}
	return (0);
}

void	ft_unset(t_stack *cp_env, char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!ft_check_variable(args[i]))
			ft_delete_variable(cp_env, args[i]);
	}
}
