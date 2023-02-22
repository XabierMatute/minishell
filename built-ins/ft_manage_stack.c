/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:17:26 by jperez            #+#    #+#             */
/*   Updated: 2023/02/22 12:26:42 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_stack	*ft_create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->len = 0;
	stack->peek = NULL;
	return (stack);
}

void	destroy_stack(t_stack *stack)
{
	while (stack->peek != NULL)
		ft_pop(stack, 0);
	free(stack);
	G_cp_env = NULL;// o asi o cambiar el imput a **stack
}

t_node	*ft_create_node(char *_variable)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->variable = _variable;
	node->next = NULL;
	return (node);
}

void	delete_node(t_node *node)
{
	free(node->variable);
	free(node);
	node = NULL;
}
