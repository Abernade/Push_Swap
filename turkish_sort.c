/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:48:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/11 12:00:47 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_lowest(t_pushswap *data, int place)
{}

void	search_lowest(t_pushswap *data,int cost)
{}

int	search_min_index(t_list *a)
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

int	count_moves_for_one(t_pushswap *data, t_ops *c)
{
	int	count;
	int	current;
	int	max_b;
	int	min_b;

	count = 0;
	max_b = search_biggest_index(data->stack_b);
	min_b = search_min_index(data->stack_b);
	while (data->stack_b)
	{
		if (data->stack_a->index > max_b)
		{
			c->psh_b++;
			return (1);
		}
		else if (data->stack_a->index < min_b)
		{
			c->psh_b++;
			c->rt_b++;
			return (2);
		}
		current = data->stack_b->index;
		if (data->stack_a->index < current)
		{
			c->rt_b++;
			data->stack_b = data->stack_b->next;
		}
	}
	if (c->rt_b > 0)
		c->revrt_b += c->rt_b;
	count = c->rt_a + c->rt_b + c->revrt_b + 1;
	return (count);
}

void	turk_sort(t_pushswap *data)
{
	int	min_total;
	int	curr_total = 10;
	int	index;
	int	i = 0;
	t_ops ops;

	indexer(data->stack_a);
	push_b(data);
	push_b(data);
	while (data->stack_a)
	{
		init_t_ops(&ops);
		ops.rt_a += i;
		curr_total = count_moves_for_one(data, &ops);
		if (curr_total < min_total)
		{
			min_total = curr_total;
			index = i;
		}
		data->stack_a = data->stack_a->next;
		i++;
	}

}
