/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:47:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/20 19:58:54 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirecti(char *comand, char **eof, char **ir)
{
	size_t	i;

	if (!comand || !eof || !ir)
		return (merror());
	i = 0;
	while (comand[i] && comand[i + 1])
	{
		if (comand[i] == '<' && comand[i + 1] != '<')
		{
			ft_here_doc(*ir);
			ir++;
		}
		else if (comand[i] == '<' && comand[i + 1] == '<')
		{
			ft_redirect_input(*eof);
			eof++;
			i++;
		}
		i++;
	}
	free(comand);
	return (1);
}

int	redirecto(char *comand, char **or, char **orae)
{
	size_t	i;

	if (!comand || !or || !orae)
		return (merror());
	i = 0;
	while (comand[i] && comand[i + 1])
	{
		if (comand[i] == '>' && comand[i + 1] != '>')
		{
			ft_redirect_output(*or, O_TRUNC);
			or++;
		}
		else if (comand[i] == '<' && comand[i + 1] == '<')
		{
			ft_redirect_output(*orae, O_APPEND);
			orae++;
			i++;
		}
		i++;
	}
	free(comand);
	return (1);
}

void	makeredirections(char *comand)
{
	char	**eof;
	char	**ir;
	char	**or;
	char	**orae;

	if (contain(comand, '<'))
	{
		eof = expandall(getir_ae(comand));
		ir = expandall(getir(comand));
		redirecti(ft_strdup(comand), eof, ir);
		ft_free_2d_arr((void **)eof);
		ft_free_2d_arr((void **)ir);
	}
	if (contain(comand, '>'))
	{
		or = expandall(getor_ae(comand));
		orae = expandall(getor(comand));
		redirecto(ft_strdup(comand), or, orae);
		ft_free_2d_arr((void **)or);
		ft_free_2d_arr((void **)orae);
	}
}
