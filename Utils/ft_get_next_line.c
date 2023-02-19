/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:41:35 by jperez            #+#    #+#             */
/*   Updated: 2023/02/19 18:43:25 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_check_str(char *str)
{
	if (str[0])
	{
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}

char	*ft_get_next_line(int fd)
{
	int		i;
	int		rd;
	char	c[2];
	char	*buf;
	char	*aux;

	rd = 1;
	i = 0;
	buf = (char *)malloc(sizeof(char) * 1);
	buf[0] = '\0';
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		c[rd] = '\0';
		aux = buf;
		buf = ft_strjoin(buf, c);
		free(aux);
		i++;
		if (c[0] == '\n')
			break ;
	}
	if ((!buf[i - 1] && !rd) || rd == -1)
		return (ft_check_str(buf));
	return (buf);
}
