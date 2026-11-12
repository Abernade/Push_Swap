/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:48:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/12 12:32:39 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	find_node(t_pushswap *data, int pos)
{
	while (data->stack_b->index != pos)
			rotate_b(data);
	push_b(data);
	rotate_b(data);
}

static void	count_ops(t_pushswap *data, t_ops *c, int max_b, int min_b)
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
		{
			c->psh_b++;
			c->rt_b++;
		}
		current = head->index;
		if (a_value < current)
			c->rt_b++;
		head = head->next;
	}
	if (c->rt_a > (data->a_size / 2))
		count_reverse_a(data, c);
	if (c->rt_b > (data->b_size / 2))
		count_reverse_b(data, c);
}

/*static void	max_on_top(t_pushswap *data)
{
	int	pos;

	pos = search_max_index(data->stack_b);
	while (pos != data->stack_b->index)
		rotate_b(data);
		}*/

static void rr(t_pushswap *data, int count)
{
	while (count > 0)
	{
		rotate_a(data);
		rotate_b(data);
		count--;
	}
}

static void	rrr(t_pushswap *data, int count)
{
	while (count > 0)
	{
		reverse_rotate_a(data);
		reverse_rotate_b(data);
		count--;
	}
}

static void	find_right_insert(t_pushswap *data)
{
	int	current;

	current = data->stack_b->index;
	printf("right insert :\ncurrent:[%d] && index:[%d]\n", current, data->stack_a->index);
	if (data->stack_a->index < current)//here
	{
		while (data->stack_a->index < current)
		{
			rotate_b(data);
			current = data->stack_b->index;
		}
	}
	if (data->stack_a->index > current)
	{
		while (data->stack_a->index > current)
		{
			reverse_rotate_b(data);
			current = data->stack_b->index;
		}
	}
	push_b(data);
}

static void	push_lowest(t_pushswap *data, t_ops *ops, t_turk *info)
{
	int	count;
	int	current;

	count_ops(data, ops, info->b_max, info->b_min);
	count = min(ops->rt_a, ops->rt_b);
	rr(data, count);
	count = min(ops->revrt_a, ops->revrt_b);
	rrr(data, count);
	if (data->stack_a->index > info->b_max)
	{
		push_b(data);
		return ;
	}
	else if (data->stack_a->index < info->b_min)
	{
		find_node(data, info->b_max);
		return ;
	}
	current = data->stack_b->index;
	if (data->stack_a->index)
		find_right_insert(data);
}

void	turk_sort(t_pushswap *data)
{
	int		pos;
	t_ops	op;
	t_turk	info;

	indexer(data->stack_a);
	push_b(data);
	push_b(data);
	while (data->stack_a)
	{
		print_stacks(data, PRINT_IDX | PRINT_NB);
		pos = search_lowest(data, &op, &info);
		printf("operations : rt_a = [%d]; rt_b = [%d]; revrt_a = [%d]; revrt_b = [%d]\n", op.rt_a, op.rt_b, op.revrt_a, op.revrt_b);
		push_lowest(data, &op, &info);
	}
	pos = search_max_index(data->stack_b);
	while (pos != data->stack_b->index)
		rotate_b(data);
	while (data->stack_b)
		push_a(data);
}
