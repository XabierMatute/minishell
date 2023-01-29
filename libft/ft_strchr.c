/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:52:48 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/22 11:50:41 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while ((str[i] != (char)c) && (str[i]))
		i++;
	if (str[i] || ((!((char)c) && !str[i])))
		return ((char *)(str + i));
	return ((char *)0);
}
