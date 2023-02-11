/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:35 by jperez            #+#    #+#             */
/*   Updated: 2023/02/11 19:46:30 by xmatute-         ###   ########.fr       */
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
	exit (55);

}
