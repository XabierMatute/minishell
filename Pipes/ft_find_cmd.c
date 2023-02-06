/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:49:27 by jperez            #+#    #+#             */
/*   Updated: 2023/02/05 20:16:52 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_find_path(t_stack *cp_env)
{
	t_node	*ptr;

	if (cp_env->peek)
	{
		ptr = cp_env->peek;
		while (ptr)
		{
			if (!ft_strncmp(ptr->variable, "PATH", 4))
				return (ptr->variable);
			ptr = ptr->next;
		}
	}
	return (NULL);
}

char	*ft_check_folder_access(char *folder, char *cmd)
{
	char	*aux_cmd;
	char	*aux_folder;

	printf("PATH: %s\n\n", folder);
	aux_cmd = ft_strjoin("/", cmd);
	aux_folder = ft_strjoin(folder, aux_cmd);
	if (!access(aux_folder, F_OK))
		return (free(aux_cmd), free(folder), aux_folder);
	free(aux_cmd);
	free(aux_folder);
	free(folder);
	return (NULL);
}

char	*ft_find_folder(char *path, char *cmd)
{
	int	i;
	int	j;
	char	*folder;

	printf("%s\n", path);
	i = 5;
	while (path[i])
	{
		j = i;
		while (path[j++] != ':' && path[j] != '\0');
		folder = ft_check_folder_access(ft_substr(path, i, j - i - 1), cmd);
		if (folder)
			return (folder);
		i = j;
	}
	return (NULL);
}

char *ft_find_cmd(t_stack *cp_env, char *cmd)
{
	char	*path;
	char	*folder;

	path = ft_find_path(cp_env);
	if (!path)
		return (NULL);
	folder = ft_find_folder(path, cmd);
	return (folder);
}
