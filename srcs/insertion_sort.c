/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 08:44:32 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/16 10:39:30 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_value(t_list *a, int sorted)
{
	t_list	*end = ft_lstlast(a);
	int		min;

	min = end->index;
	while (sorted > 0)
	{
		if (min < end->index)
			min = end->index;
		end = end->prev;
		sorted--;
	}
	return (min);
}

static void	search_right_insert(int sorted, t_pushswap *data)
{
	int	count;
	int value_a;
	int value_b;
	int sorted_min;

	count = 0;
	while (sorted > count)
	{
		value_a = *(int *)data->stack_a->content;
		value_b = *(int *)data->stack_b->content;
		sorted_min = search_min_value(data->stack_a, sorted);
		if (sorted_min > value_b)
		{
			reverse_multi_rotations(data, sorted, 'a');
			push_a(data);
			multi_rotations(data, sorted + 1, 'a');
			return ;
		}
		else if (value_a < value_b)
		{
			push_a(data);
			multi_rotations(data, count, 'a');
			return ;
		}
		reverse_rotate_a(data);
		count++;
	}
}

void	insertion_sort(t_pushswap *data, int size)
{
	int	sorted;
	int	value_a;
	int	value_a1;

	value_a = *(int *)data->stack_a->content;
	value_a1 = *(int *)data->stack_a->next->content;
	sorted = 0;
	if (value_a > value_a1)
	{
		swap_a(data);
		multi_rotations(data, 2, 'a');
	}
	else
		multi_rotations(data, 2, 'a');
	sorted = 2;
	while (sorted < size && data->stack_b)
	{
		push_b(data);
		search_right_insert(sorted, data);
		sorted++;
	}
}
