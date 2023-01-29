/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:15:27 by jperez            #+#    #+#             */
/*   Updated: 2023/01/29 17:20:46 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<limits.h>

#include"ft_pwd.c"

int	ft_abs_or_rel(char *path)
{
	if (*path == '/')
		return (1);
	return (0);
}

int	ft_check_access(char *path)
{
	if (access(path, F_OK | R_OK))
	{
		perror("cd");
		printf("%s\n", path);
		return (1);
	}
	return (0);
}

void	ft_cd(char *path)
{
	char	buff[PATH_MAX];

	getcwd(buff, PATH_MAX);
	ft_abs_or_rel(path);
	ft_check_access(path);
	chdir(path);
}

int main()
{
	 ft_pwd();
	 ft_cd("aaaa");
	 ft_pwd();
}
