/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:31:19 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/13 11:22:13 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// returns 0 on success, returns 1 on malloc error
int	rotate_a(t_pushswap *data)
{
	t_list	*node;

	node = data->stack_a;
	if (!node || !node->next)
		return (0);
	data->stack_a = node->next;
	ft_lstadd_back(&data->stack_a, node);
	if(add_instr(&data->instructions, RA))
		return (1);
	return (0);
}

int	rotate_b(t_pushswap *data)
{
	t_list	*node;

	node = data->stack_b;
	if (!node || !node->next)
		return (0);
	data->stack_b = node->next;
	ft_lstadd_back(&data->stack_b, node);
	if(add_instr(&data->instructions, RB))
		return (1);
	return (0);
}

int	reverse_rotate_a(t_pushswap *data)
{
	t_list	*node;

	node = ft_lstlast(data->stack_a);
	if (!node || !node->prev)
		return (0);
	node->prev->next = NULL;
	ft_lstadd_front(&data->stack_a, node);
	if(add_instr(&data->instructions, RRA))
		return (1);
	return (0);
}

int	reverse_rotate_b(t_pushswap *data)
{
	t_list	*node;

	node = ft_lstlast(data->stack_b);
	if (!node || !node->prev)
		return (0);
	node->prev->next = NULL;
	ft_lstadd_front(&data->stack_b, node);
	if (add_instr(&data->instructions, RRB))
		return (1);
	return (0);
}
