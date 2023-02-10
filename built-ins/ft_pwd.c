/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:35 by jperez            #+#    #+#             */
/*   Updated: 2023/02/10 16:48:26 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

static int	ft_check_args(char **args)
{
	if (ft_args_lenght(args) != 0)
	{
		ft_printf("❌ env: to many arguments\n");
		return (1);
	}
	return (0);
}

void	ft_pwd(char **args)
{
	char	buff[PATH_MAX];

	if (ft_check_args(args))
		return ;
	getcwd(buff, PATH_MAX);
	ft_printf("%s\n", buff);
}
