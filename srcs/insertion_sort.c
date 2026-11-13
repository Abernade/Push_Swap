/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 08:44:32 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/13 17:13:52 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_a(t_pushswap *data, int sorted)
{
	int	i;

	i = 0;
	while (i <= sorted)
	{
		reverse_rotate_b(data);
		push_a(data);
		sorted--;
	}
}

static void	searching_on_going(t_pushswap *data, int a, int b, int b_max)
{
	int	count;

	count = 0;
	if (a > b_max)
	{
		push_b(data);
		b_max = *(int *)data->stack_b->content;
		rotate_b(data);
	}
	else
	{
		while (b < a)
		{
			rotate_b(data);
			count++;
			b = *(int *)data->stack_b->content;
		}
		push_b(data);
		while (count > 0)
		{
			reverse_rotate_b(data);
			count--;
		}
	}
}

t_list	*insertion_sort(t_pushswap *data, int size)
{
	int	sorted;
	int	a;
	int	b;
	int	b_max;

	sorted = 0;
	push_b(data);
	b_max = *(int *)data->stack_b->content;
	while (sorted < size - 1 && data->stack_a)
	{
		b = *(int *)data->stack_b->content;
		a = *(int *)data->stack_a->content;
		if (a < b)
			push_b(data);
		else
			searching_on_going(data, a, b, b_max);
		sorted++;
	}
	push_back_a(data, sorted);
	return (data->stack_a);
}
