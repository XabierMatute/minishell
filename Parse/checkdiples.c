/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdiples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:06:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/02 12:16:59 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	last(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	i--;
	while (s[i] == ' ' && i > 0)
	{
		i--;
	}
	if (s[i] == '<' || s[i] == '>')
	{
		ft_printf("❌Error: el diple no puede ir al final\n");
		return (1);
	}
	return (0);
}

static int	alone(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		while ((s[i] != '<' && s[i] != '>') && s[i])
			i += 1 + ignoreq(s + i) - (s + i);
		if (s[i])
			i++;
		if (s[i] == s[i - 1])
			i++;
		while (s[i] == ' ' && s[i])
			i++;
		if ((s[i] == '<' || s[i] == '>') && s[i])
		{
			ft_printf("💀Error: no pongas mas de un diple seguido por favor\n");
			return (0);
		}
	}
	return (1);
}

int	checkdiples(char *s)
{
	return (!last(s) && alone(s));
}
