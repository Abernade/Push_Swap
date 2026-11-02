/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:31:19 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/02 15:20:44 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pushswap *data)
{
	t_list	*node;

	node = data->stack_a;
	if (!node || !node->next)
		return ;
	data->stack_a = node->next;
	ft_lstadd_back(&data->stack_a, node);
}

void	rotate_b(t_pushswap *data)
{
	t_list	*node;

	node = data->stack_b;
	if (!node || !node->next)
		return ;
	data->stack_b = node->next;
	ft_lstadd_back(&data->stack_b, node);
}

void	reverse_rotate_a(t_pushswap *data)
{
	t_list	*node;

	node = ft_lstlast(data->stack_a);
	if (!node || !node->prev)
		return ;
	node->prev->next = NULL;
	ft_lstadd_front(&data->stack_a, node);
}

void	reverse_rotate_b(t_pushswap *data)
{
	t_list	*node;

	node = ft_lstlast(data->stack_b);
	if (!node || !node->prev)
		return ;
	node->prev->next = NULL;
	ft_lstadd_front(&data->stack_b, node);
}
