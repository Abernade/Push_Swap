/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 08:49:19 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/12 12:31:33 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* the aim of the function is either to find the right nm of rotation for the
 * right insertion either i dont remember */
/*static int	find_right_insert()
	{}*/

void	count_reverse_a(t_pushswap *data, t_ops *c)
{
	c->revrt_a = data->a_size - c->rt_a;
	c->rt_a = 0;
}

void	count_reverse_b(t_pushswap *data, t_ops *c)
{
	c->revrt_b = data->b_size - c->rt_b;
	c->rt_b = 0;
}

static int	count_moves_for_one(t_pushswap *data, t_ops *c, t_turk *info)
{
	t_list *head;
	int		count;

	info->a_value = data->stack_a->index;
	info->b_max = search_max_index(data->stack_b);
	info->b_min = search_min_index(data->stack_b);
	head = data->stack_b;
	while (head)
	{
		if (info->a_value > info->b_max)
		{
			c->psh_b++;
			return (1);
		}
		else if (info->a_value < info->b_min)
		{
			c->psh_b++;
			c->rt_b++;
			return (2);
		}
		info->current = head->index;
		if (info->a_value < info->current)
			c->rt_b++;
		head = head->next;//chg
	}
	if (c->rt_a > (data->a_size / 2))
		count_reverse_a(data, c);
	if (c->rt_b > (data->b_size / 2))
		count_reverse_b(data, c);
	count = c->rt_a + c->rt_b + c->revrt_a + c->revrt_b + 1;
	// possible fonction a faire ici pour etre précis
	return (count);
}

int	search_lowest(t_pushswap *data, t_ops *op, t_turk *info)
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
		init_t_ops(op);
		moves = count_moves_for_one(data, op, info);
		if (moves < min_moves)
		{
			min_moves = moves;
			pos = rotations;
		}
		head = head->next;
		rotations++;
	}
	op->rt_a = pos;
	return (pos);
}
