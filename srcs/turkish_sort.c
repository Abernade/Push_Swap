/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:48:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/11 17:29:32 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_min_index(t_list *a)
{
	int	min;

	min = a->index;
	while (a)
	{
		if (min > a->index)
			min = a->index;
		a = a->next;
	}
	return (min);
}

static void	find_node(t_pushswap *data, int pos)
{
	while (data->stack_b->index != pos)
			rotate_b(data);
	push_b(data);
	rotate_b(data);
}

static int	count_moves_for_one(t_pushswap *data, t_ops *c)
{
	int	count;
	int	current;
	int	a_value;
	int	max_b;
	int	min_b;
	t_list *head;

	count = 0;
	a_value = data->stack_a->index; //chg
	max_b = search_biggest_index(data->stack_b);
	min_b = search_min_index(data->stack_b);
	head = data->stack_b;
	while (head)
	{
		if (a_value > max_b)
		{
			c->psh_b++;
			return (1);
		}
		else if (a_value < min_b)
		{
			c->psh_b++;
			c->rt_b++;
			return (2);
		}
		current = head->index;
		if (a_value < current)
			c->rt_b++;
		head = head->next;//chg
	}
	count = c->rt_a + c->rt_b + 1;
	return (count);
}

static int	count_ops(t_pushswap *data, t_ops *c, int max_b, int min_b)
{
	int	count;
	int	current;
	int	a_value;
	t_list *head;

	count = 0;
	a_value = data->stack_a->index;
	head = data->stack_b;
	while (head)
	{
		if (a_value > max_b)
			c->psh_b++;
		else if (a_value < min_b)
			c->psh_b++;
			c->rt_b++;
		current = head->index;
		if (a_value < current)
			c->rt_b++;
		head = head->next;
	}
}

static int	search_lowest(t_pushswap *data, t_ops *op)
{
	int	min_total = data->a_size + 1;
	int	curr_total = 10;
	int	index = 0;
	int	i = 0;
	t_list *head;

	head = data->stack_a;
	while (head)
	{
		op->rt_a += i;
		curr_total = count_moves_for_one(data, op);
		if (curr_total < min_total)
		{
			min_total = curr_total;
			index = i;
		}
		head = head->next;
		i++;
	}
	return (index);
}

static void	push_lowest(t_pushswap *data, int pos, t_ops *ops)
{
	int	count;
	int	current;
	int	max_b;
	int	min_b;

	count = 0;
	max_b = search_biggest_index(data->stack_b);
	min_b = search_min_index(data->stack_b);
	count_ops(data, ops, max_b, min_b);
	count = min(ops->rt_a, ops->rt_b);
	while (count > 0)
	{
		rotate_a(data);
		rotate_b(data);
		count--;
	}
	while (data->stack_b)
	{
		if (data->stack_a->index > max_b)
		{
			push_b(data);
			return ;
		}
		else if (data->stack_a->index < min_b)
		{
			find_node(data, max_b);
			return ;
		}
		current = data->stack_b->index;
		if (data->stack_a->index < current)//here
			rotate_b(data);
		else
		{
			push_b(data);
			return ;
		}
	}
}

void	turk_sort(t_pushswap *data)
{
	int pos;
	t_ops op;

	indexer(data->stack_a);
	push_b(data);
	push_b(data);
	while (data->stack_a)
	{
		init_t_ops(&op);
		pos = search_lowest(data, &op);
		op.rt_a = pos;
		push_lowest(data, pos, &op);
	}
	pos = search_biggest_index(data->stack_b);
	while (pos != data->stack_b->index)
		rotate_b(data);
	while (data->stack_b)
		push_a(data);
}
