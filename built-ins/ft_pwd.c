/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:35 by jperez            #+#    #+#             */
/*   Updated: 2023/01/29 16:33:39 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<limits.h>

void	ft_pwd()
{
	char	buff[PATH_MAX];

	getcwd(buff, PATH_MAX);
			printf("%s\n", buff);
}
