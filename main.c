/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:03 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/01 19:23:39 by xmatute-         ###   ########.fr       */
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


int main()
{
	char	*str;

	str = NULL;
	while(1)
	{
		str = readline("🐚👉");
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
    return 0;
}

/*
** Gestionar ctrl-C ctrl-D ctrl-\, que deberán funcionar como en bash.
** •Cuando sea interactivo:
** ◦ctrl-C imprime una nueva entrada en una línea nueva.
** ◦ctrl-D termina el shell.
** ◦ctrl-\ no hace nada.
*/