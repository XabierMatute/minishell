/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:20:48 by jperez            #+#    #+#             */
/*   Updated: 2023/02/28 16:59:54 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_node	*ft_get_selected_node(t_stack *stack, int index)
{
	int		i;
	t_node	*ptr;

	if (stack->peek)
	{
		if (stack->peek->next)
		{
			ptr = stack->peek;
			i = -1;
			while (ptr->next && ++i < index)
				ptr = ptr->next;
			return (ptr);
		}
		else
			return (stack->peek);
	}
	return (NULL);
}

void	ft_push(t_stack *stack, char *variable)
{
	t_node	*node;

	node = ft_create_node(variable);
	if (stack->peek)
		ft_get_selected_node(stack, stack->len)->next = node;
	else
		stack->peek = node;
	stack->len++;
}

void	ft_pop(t_stack *stack, int index)
{
	t_node	*aux;
	t_node	*to_delete;

	if (stack->peek == NULL)
		return ;
	if (index == 0)
	{
		aux = stack->peek->next;
		delete_node(stack->peek);
		stack->peek = aux;
	}
	else
	{
		aux = ft_get_selected_node(stack, index - 1);
		to_delete = aux->next;
		aux->next = to_delete->next;
		delete_node(to_delete);
	}
	stack->len--;
}
