/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:03 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/10 17:22:38 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

#include <readline/readline.h>
#include <readline/history.h>

#include <readline/readline.h>
#include <readline/history.h>
// int main(int argc, char *argv[])
// {
// 	if (validsintax(argv[argc - 1]))
// 	{
// 		printf("\"%s\" es una sintaxis valida", argv[1]);
// 	}
// 	else
// 		printf("\"%s\" no es una sintaxis valida", argv[1]);
	
// 	return 0;
// }


int main(int argc, char **argv, char **env)
{
	char	*str;

	printf("--->%d\n", ft_strisalnum("'fff fff'"));
	str = NULL;
	ft_create_env(env);
	printf("PID: %d\n\n", getpid());
	while(1)
	{
		//ft_add_listener();
		ft_add_father_listener();
		str = readline("minishel: ");
		if (str == NULL)
			exit(-1);
		if (*str != '\0')
		{
			//cambiar letras de señales
			add_history(str);
			if (validsintax(str))
			{
				if (ft_manage_builtins(str) == 0)
					ft_family_process(ft_create_pipes(0), ft_split(str, ' '), 0);
				// pipes(ft_split(str, '|'));//si split da NULL-> ERROR
			}
			else
				printf("\"%s\" no es una sintaxis valida\n", str);
			free(str);
		}
	}
    return 0;
}

/*
** Gestionar ctrl-C ctrl-D ctrl-\, que deberán funcionar como en bash.
** •Cuando sea interactivo:
** ◦ctrl-C imprime una nueva entrada en una línea nueva.
** ◦ctrl-D termina el shell.
** ◦ctrl-\ no hace nada.
*/
