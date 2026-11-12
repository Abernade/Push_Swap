/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:48:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/12 15:45:58 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	insert_max_node(t_pushswap *data, int pos)
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

static void	find_right_insert(t_pushswap *data, t_ops *c)
{
	int	current;
	(void)c;

	current = data->stack_b->index;
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

static void	push_lowest(t_pushswap *data, int pos, t_turk *info)
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
	rr(data, moves, curr);
	while (curr->rt_a > 0)
	{
		rotate_a(data);
		curr->rt_a--;
	}
	while (curr->rt_b > 0)
	{
		rotate_b(data);
		curr->rt_b--;
	}
	while (curr->revrt_a > 0)
	{
		reverse_rotate_a(data);
		curr->revrt_a--;
	}
	while (curr->revrt_b > 0)
	{
		reverse_rotate_b(data);
		curr->revrt_b--;
	}
	push_b(data);
}

/* *
 * cette fonction cherche l'element de a qui necessite le moins
 * de coup pour bouger dans la struct.
 * */
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
		push_lowest(data, pos);//
	}
	pos = search_max_index(data->stack_b);
	while (pos != data->stack_b->index)
		rotate_b(data);
	while (data->stack_b)
		push_a(data);
}
