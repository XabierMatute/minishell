/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:31:33 by jperez            #+#    #+#             */
/*   Updated: 2023/02/16 14:51:27 by xmatute-         ###   ########.fr       */
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
	if (!ft_strisalnum(variable))
	{
		ft_printf("❌ unset: '%s': not a valid identifier\n", variable);
		return (1);
	}
	return (0);
}

int	ft_unset(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!ft_check_variable(args[i]))
			ft_delete_variable(G_cp_env, args[i]);
	}
	return (55);

}
