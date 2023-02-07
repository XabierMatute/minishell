/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:03 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/07 19:42:11 by jperez           ###   ########.fr       */
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

	str = NULL;
	ft_create_env(env);
	while(1)
	{
		ft_add_listener();
		str = readline("minishel: ");
		if (str == NULL)
			exit(-1);
		if (*str != '\0')
		{
			//cambiar letras de señales
			if (!strncmp(str, "exit", 4))
				exit(-1);
			add_history(str);
			if (validsintax(str))
			{
				printf("\"%s\" es una sintaxis valida\n", str);
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
