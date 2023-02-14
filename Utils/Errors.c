/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:38:50 by xmatute-          #+#    #+#             */
/*   Updated: 2023/02/13 20:44:45 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int merror(void)
{
	ft_printf("⚠️Error de memoria\n");
	destroy_stack(G_cp_env);
	return (1);
}

int rerror(void)
{
	ft_printf("⚠️Error en las redirecciones\n");
	destroy_stack(G_cp_env);
	return (1);
}

int serror(void)
{
	ft_printf("⚠️Error en las señales\n");
	destroy_stack(G_cp_env);
	return (1);
}