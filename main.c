/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:03 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/14 13:22:45 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	
	env2 = env;
	if (!ft_create_env(env))
	{
		ft_printf("⚠️Error de enviroment\n");
		return(3);
	}
				// printf("PID: %d\n\n", getpid());
    return (minishell());
}
