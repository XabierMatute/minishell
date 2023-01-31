/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:09:40 by jperez            #+#    #+#             */
/*   Updated: 2023/01/31 19:43:46 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_variable(char **env, char *variable)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	env[i++] = variable;
	env[i] = NULL;
}

int ft_check_variable(char *variable)
{
	int	equal_pos;

	equal_pos = ft_strchr(variable, '=') - variable;
	printf("%d\n", equal_pos);
	if (equal_pos <= 0)
		return (1);
	return (0);
}

void	ft_export_error(char *variable)
{
	int equal_pos;

	equal_pos = ft_strchr(variable, '=') - variable;
	
}

void	ft_export(char **env, char **variables)
{
	int	i;

	i = -1;
	while (variables[++i])
	{
		if (!ft_check_variable(variables[i]))
			ft_add_variable(env, variables[i]);
		else
			ft_printf("Error\n");
	}
}
