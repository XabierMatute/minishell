/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:23:19 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/18 18:37:31 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t elen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l] && s[l] != 39 && s[l] != 36 && s[l] != 34)
		l++;
	return (l);
}

char *expand(char *s)
{
	char	*e;
	size_t	l;
	
	if (!s)
		return(0);
	if (!*s)
		return(ft_strdup(""));
	if (*s == 39)
		return (expand39(s + 1));
	if (*s == 36)
		return (expand36(s + 1));
	if (*s == 34)
		return (expand34(s + 1));
	l = elen(s);
	// printf("l = %i\n", l);

	e = ft_calloc(l + 1, sizeof(char));
	if (!e)
		return(0);//printear error de memoria
	while (l--)
		e[l] = s[l];
	// printf("e = %s\n", e);
	return (ft_strjoinfree(e, expand(s + ft_strlen(e))));
}

char	**expandall(char **ss)
{
	char	**e;
	size_t	i;

	if (!ss)
		return (0);
	e = malloc(sizeof(char *) * (ft_args_lenght(ss) + 1));
	if (!e)
		return (0);
	
	i = 0;
	while (ss[i])
	{
		e[i] = expand(ss[i]);
		if	(!e[i])
		{
			ft_free_2d_arr((void **)e);
			return (0);
		}
		i++;
	}
	e[i] = 0;
	return (e);	
}//en general cubrete de errores de memoria
// int main(int argc, char const *argv[])
// {
// 	// while (argc --)
// 	// {
// 	// 	printf("%s->%s\n", argv[argc], expand(argv[argc]));
// 	// }
// 	// printf("%s->%s\n", "m\'ira y\'\'o que s\'\'e 'bro\'", expand("m\'ira y\'\'o que s\'\'e 'bro\'"));
	
// 	printf("%s\n", expand(NULL));

// 	printf("%s\n", expand(""));
// 	printf("%s\n", expand("ey"));
// 	printf("%s\n", expand("aupa"));
// 	printf("%s\n", expand("\'aupa\'"));
// 	printf("%s\n", expand("ey \'au\"pa\' babyboy"));
// 	printf("%s\n", expand("ey \'au\"pa\'"));
// 	return 0;
// }
