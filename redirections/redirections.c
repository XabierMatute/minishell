/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:47:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/05 19:02:55 by jperez           ###   ########.fr       */
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
			ft_redirect_input(*ir);
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
		else if (comand[i] == '>' && comand[i + 1] == '>')
		{
			ft_redirect_output(*orae, O_APPEND);
			orae++;
			i++;
		}
		i++;
	}
	return (1);
}

int	makeredirections(char *comand)
{
	char	**eof;
	char	**ir;
	char	**or;
	char	**orae;
	char	*aux;

	aux = ft_strdup(comand);
	if (contain(comand, '<'))
	{
		eof = expandall(getir_ae(comand));
		ir = expandall(getir(comand));
		if (redirecti(aux, eof, ir) == 2)
			return (ft_free_2d_arr((void **)eof), ft_free_2d_arr((void **)ir), free(aux), 1);
		ft_free_2d_arr((void **)eof);
		ft_free_2d_arr((void **)ir);
	}
	if (contain(comand, '>'))
	{
		orae = expandall(getor_ae(comand));
		
		or = expandall(getor(comand));
		redirecto(aux, or, orae);
		ft_free_2d_arr((void **)or);
		ft_free_2d_arr((void **)orae);
	}
	if (aux)
		free(aux);
	return (0);
}
