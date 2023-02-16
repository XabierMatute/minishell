/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:21:27 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/15 17:51:39 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(void)
{
	char	*str;

	str = NULL;
	while (G_cp_env)
	{
		if(ft_add_father_listener())
			serror();
		str = readline("minishell: ");
		if (str == NULL)
			ft_exit(G_cp_env);
		if (*str != '\0')
		{
			if (!ft_strncmp(str, "exit", ft_strlen(str)))
			{
				ft_printf("%s\n", str);
				ft_exit(G_cp_env);
			}
			add_history(str);
			if (validsintax(str))
				pipes(ft_split(str, '|'));
		}
		free(str);
	}
	return (0);
}
