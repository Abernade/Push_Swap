/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:26:38 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/10 15:06:30 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_pushswap *data)
{
	t_list	*next_b;

	if (!data->stack_b)
		return (0);
	next_b = data->stack_b->next;
	if (data->stack_a)
	{
		if (data->stack_b->next)
			data->stack_b->next->prev = NULL;
		data->stack_b->next = data->stack_a;
		data->stack_a->prev = data->stack_b;
	}
	else
		data->stack_b->next = NULL;
	data->stack_a = data->stack_b;
	data->stack_b = next_b;
	if (next_b)
		next_b = NULL;
	if(add_instr(data, PA))
		return (1);
	data->a_size++;
	data->b_size--;
	return (0);
}

int	push_b(t_pushswap *data)
{
	t_list	*next_a;

	if (!data->stack_a)
		return (0);
	next_a = data->stack_a->next;
	if (data->stack_b)
	{
		if (data->stack_a->next)
			data->stack_a->next->prev = NULL;
		data->stack_a->next = data->stack_b;
		data->stack_b->prev = data->stack_a;
	}
	else
		data->stack_a->next = NULL;
	data->stack_b = data->stack_a;
	data->stack_a = next_a;
	if (next_a)
		next_a->prev = NULL;
	if(add_instr(data, PB))
		return (1);
	data->a_size--;
	data->b_size++;
	return (0);
}

int	swap_a(t_pushswap *data)
{
	t_list	*second_node;

	if (!data->stack_a || !data->stack_a->next)
		return (0);
	second_node = data->stack_a->next;
	data->stack_a->next = second_node->next;
	data->stack_a->prev = second_node;
	second_node->next = data->stack_a;
	data->stack_a = second_node;
	second_node->prev = NULL;
	if (add_instr(data, SA))
		return (1);
	return (0);
}

int	swap_b(t_pushswap *data)
{
	t_list	*second_node;

	if (!data->stack_b || !data->stack_b->next)
		return (0);
	second_node = data->stack_b->next;
	data->stack_b->next = second_node->next;
	data->stack_b->prev = second_node;
	second_node->next = data->stack_b;
	data->stack_b = second_node;
	second_node->prev = NULL;
	if (add_instr(data, SB))
		return (1);
	return (0);
}
