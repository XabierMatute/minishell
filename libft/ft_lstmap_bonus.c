/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:47:22 by xmatute-          #+#    #+#             */
/*   Updated: 2022/09/23 11:38:16 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*mapi;
	void	*a;

	mapi = 0;
	while (lst)
	{
		a = f(lst->content);
		node = ft_lstnew(a);
		if (!node)
		{
			free(a);
			ft_lstclear(&mapi, del);
			return (0);
		}
		ft_lstadd_back(&mapi, node);
		lst = lst->next;
	}
	return (mapi);
}
