/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:47:03 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 18:08:51 by xmatute-         ###   ########.fr       */
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
	int		j;
	char	*str;
	char	**cl;
	char	**wl;

	str = NULL;
	while(1)
	{
		str = readline("👉");
		add_history(str);
		if (validsintax(str))
			printf("\"%s\" es una sintaxis valida\n", str);
		else
			printf("\"%s\" no es una sintaxis valida\n", str);
		cl = ft_split(str, '|');
		i = 0;
		while (cl[i])
		{
			// wl = ft_split(cl[i], ' ');
			ft_printf("%s\n|\n", cl[i]);
			i++;
		}
		printf("%s\n", cl[i]);

		
		free(str);
	}
    return 0;
}