/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:03 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 16:40:54 by xmatute-         ###   ########.fr       */
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
	int		i;
	char	*str;
	i = -1;
	str = NULL;
	while(1)
	{
		str = readline("👉");
		add_history(str);
		if (validsintax(str))
		{
			printf("\"%s\" es una sintaxis valida\n", str);
		}
		else
			printf("\"%s\" no es una sintaxis valida\n", str);

		free(str);
	}
    return 0;
}