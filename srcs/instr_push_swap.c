/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:26:38 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/02 15:06:21 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pushswap *data)
{
	t_list	*next_b;

	if (!data->stack_b)
		return ;
	next_b = data->stack_b->next;
	if (data->stack_a)
	{
		data->stack_b->next->prev = NULL;
		data->stack_b->next = data->stack_a;
		data->stack_a->prev = data->stack_b;
	}
	else
		data->stack_b->next = NULL;
	data->stack_a = data->stack_b;
	data->stack_b = next_b;
}

void	push_b(t_pushswap *data)
{
	t_list	*next_a;

	if (!data->stack_a)
		return ;
	next_a = data->stack_a->next;
	if (data->stack_b)
	{
		data->stack_a->next->prev = NULL;
		data->stack_a->next = data->stack_b;
		data->stack_b->prev = data->stack_a;
	}
	else
		data->stack_a->next = NULL;
	data->stack_b = data->stack_a;
	data->stack_a = next_a;
}

void	swap_a(t_pushswap *data)
{
	t_list	*second_node;

	if (!data->stack_a || !data->stack_a->next)
		return ;
	second_node = data->stack_a->next;
	data->stack_a->next = second_node->next;
	data->stack_a->prev = second_node;
	second_node->next = data->stack_a;
	data->stack_a = second_node;
	second_node->prev = NULL;
}

void	swap_b(t_pushswap *data)
{
	t_list	*second_node;

	if (!data->stack_b || !data->stack_b->next)
		return ;
	second_node = data->stack_b->next;
	data->stack_b->next = second_node->next;
	data->stack_b->prev = second_node;
	second_node->next = data->stack_b;
	data->stack_b = second_node;
	second_node->prev = NULL;
}
