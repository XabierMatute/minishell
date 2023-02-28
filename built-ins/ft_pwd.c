/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:35 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 17:01:55 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

static int	ft_check_args(char **args)
{
	if (ft_args_lenght(args) > 0)
	{
		ft_printf("❌ env: to many arguments\n");
		return (1);
	}
	return (0);
}

char	*ft_getpwd(void)
{
	char	*pwd;

	pwd = (char *)malloc(sizeof(char) * PATH_MAX);
	getcwd(pwd, PATH_MAX);
	return (pwd);
}

int	ft_pwd(char **args)
{
	char	*pwd;

	if (ft_check_args(args))
		return (1);
	pwd = ft_getpwd();
	ft_printf("%s\n", pwd);
	free(pwd);
	return (0);
}
