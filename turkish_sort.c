/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:48:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/11 11:30:38 by vldryga          ###   ########.fr       */
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
	int	value;
	int	current;
	int	max_b;
	int	min_b;

	count = 0;
	max_b = search_biggest_index(data->stack_b);
	min_b = search_min_index(data->stack_b);
	value = data->stack_a->index;
	while (data->stack_a)
	{
		current = data->stack_b->index;
		while (data->stack_b)
		{
			if (value > max_b)
				return (1);
			if (value < min_b)
				return (2);
			else if (value < current)
			{
				count++;
				data->stack_b = data->stack_b->next;
			}
			else
				return (count);
		}
	}
	return (0);
}

void	turk_sort(t_pushswap *data)
{
	int cost;
	int	min_total;
	int	curr_total;
	int	i;
	t_ops ops;

	indexer(data->stack_a);
	push_b(data);
	push_b(data);
	while (data->stack_a)
	{
		init_t_ops(&ops);
		curr_total = count_moves_for_one(data, &ops);
		if (curr_total < min_total)
			min_total = curr_total;
		else
			i++;
		data->stack_a = data->stack_a->next;
	}

}
