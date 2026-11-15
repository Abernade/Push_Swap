/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:48:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/13 10:00:59 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rr(t_pushswap *data, int count, t_ops *c)
{
	while (count > 0)
	{
		rotate_a(data);
		rotate_b(data);
		c->rt_a--;
		c->rt_b--;
		count--;
	}
}

static void	rrr(t_pushswap *data, int count, t_ops *c)
{
	while (count > 0)
	{
		reverse_rotate_a(data);
		reverse_rotate_b(data);
		c->revrt_a--;
		c->revrt_b--;
		count--;
	}
}

static void	push_lowest(t_pushswap *data, int pos)
{
	t_list	*head = data->stack_a;
	t_ops	*curr;
	int		moves;

	while (pos > 0)
	{
		head = head->next;
		pos--;
	}
	curr = &head->prevision;
	moves = min(curr->rt_a, curr->rt_b);
	rr(data, moves, curr);
	moves = min(curr->revrt_a, curr->revrt_b);
	rrr(data, moves, curr);
	while (curr->rt_a > 0)
	{
		rotate_a(data);
		curr->rt_a--;
	}
	while (curr->revrt_a > 0)
	{
		reverse_rotate_a(data);
		curr->revrt_a--;
	}
	while (curr->rt_b > 0)
	{
		rotate_b(data);
		curr->rt_b--;
	}
	while (curr->revrt_b > 0)
	{
		reverse_rotate_b(data);
		curr->revrt_b--;
	}
	push_b(data);
}

int	search_lowest(t_pushswap *data, t_turk *info)
{
	int	moves;
	int	min_moves;
	int	pos;
	int	rotations;
	t_list *head;

	min_moves = data->a_size + 1; //just an init
	moves = data->a_size + 1; //just an init
	pos = 0;
	rotations = 0;
	head = data->stack_a;
	while (head)
	{
		moves = count_moves_for_one(data, info, rotations);
		if (moves < min_moves)
		{
			min_moves = moves;
			pos = rotations;
		}
		head = head->next;
		rotations++;
	}
	return (pos);
}


static void	back_in_a(t_pushswap *data)
{
	int	max;

	max = search_max_index(data->stack_b);
	while (data->stack_b->index != max)
		rotate_b(data);
	while (data->stack_b)
		push_a(data);
}

void	turk_sort(t_pushswap *data)
{
	int		pos;
	t_turk	info;

	indexer(data->stack_a);
	push_b(data);
	push_b(data);
	while (data->stack_a)
	{
		pos = search_lowest(data, &info);
		push_lowest(data, pos);
	}
	print_stacks(data, PRINT_IDX | PRINT_NB);
	back_in_a(data);
}
