/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:06:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/01 18:51:39 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	first(char *s)
{
	while (*s == ' ')
	{
		s++;
	}
	if (*s == '|')
	{
		ft_printf("❌Error: el pipe no puede ir al principio\n");
		return(1);

	}
	return (0);
}

static int	last(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	i--;
	while (s[i] == ' ')
	{
		i--;
	}
	if (s[i] == '|')
	{
		ft_printf("😞Error: no interpreto el pipe al final\n");
		return(1);
	}
	return (0);
}

static int	alone(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		while (s[i] != '|' && s[i])
		{
			i++;
		}
		if (s[i])
		{
			i++;
		}
		while (s[i] == ' ' && s[i])
		{
			i++;
		}
		if (s[i] == '|' && s[i])
		{
			ft_printf("💀Error: no pongas mas de un pipe seguido por favor\n");
			return(0);
		}
	}
	return (1);
}

int	checkpipes(char *s)
{
		return (!first(s) &&
				!last(s) &&
				alone(s));
}