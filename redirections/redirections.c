/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:47:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/06 19:55:38 by xmatute-         ###   ########.fr       */
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
			if (ft_redirect_input(*ir))
				return (1);
			ir++;
		}
		else if (comand[i] == '<' && comand[i + 1] == '<')
		{
			if (ft_here_doc(*eof))
				return (2);
			eof++;
			i++;
		}
		i++;
	}
	return (0);
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
			if (ft_redirect_output(*or, O_TRUNC))
				return (1);
			or++;
		}
		else if (comand[i] == '>' && comand[i + 1] == '>')
		{
			if (ft_redirect_output(*orae, O_APPEND))
				return (2);
			orae++;
			i++;
		}
		i++;
	}
	return (0);
}

int	makeire(char *comand, char *aux)
{
	char	**eof;
	char	**ir;

	if (contain(comand, '<'))
	{
		eof = expandall(getir_ae(comand));
		ir = expandall(getir(comand));
		if (redirecti(aux, eof, ir))
			return (ft_free_2d_arr((void **)eof)
				, ft_free_2d_arr((void **)ir), 1);
		ft_free_2d_arr((void **)eof);
		ft_free_2d_arr((void **)ir);
	}
	return (0);
}

int	makeore(char *comand, char *aux)
{
	char	**or;
	char	**orae;

	if (contain(comand, '>'))
	{
		orae = expandall(getor_ae(comand));
		or = expandall(getor(comand));
		if (redirecto(aux, or, orae))
			return (ft_free_2d_arr((void **)or)
				, ft_free_2d_arr((void **)orae), 1);
		ft_free_2d_arr((void **)or);
		ft_free_2d_arr((void **)orae);
	}
	return (0);
}

int	makeredirections(char *comand)
{
	char	*aux;

	aux = ft_strdup(comand);
	if (!aux)
		return (merror());
	if (makeire(comand, aux) || makeore(comand, aux))
		return (free(aux), 1);
	if (aux)
		free(aux);
	return (0);
}
