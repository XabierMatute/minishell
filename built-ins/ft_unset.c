/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:31:33 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 17:02:50 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_find_variable(t_stack *cp_env, char *variable, int lenght)
{
	int		i;
	t_node	*ptr;

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

int	ft_unset(char **args)
{
	int	i;
	int	output;

	output = 0;
	i = -1;
	while (args[++i])
	{
		if (!ft_check_variable_name(args[i]))
			ft_delete_variable(G_cp_env, args[i]);
		else
			output = 1;
	}
	return (output);
}
