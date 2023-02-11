/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:21:27 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/11 21:34:04 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell(void)
{
	char	*str;

	str = NULL;
	while (G_cp_env)
	{
		ft_add_father_listener();
		str = readline("minishell: ");
		if (str == NULL)
			exit(-1);
		if (*str != '\0')
		{
			if (!strncmp(str, "exit", ft_strlen(str)))
				exit(-1);
			add_history(str);
			if (validsintax(str))
				pipes(ft_split(str, '|'));
		}
		if (str)
			free(str);
		str = NULL;
	}
	return (0);
}
