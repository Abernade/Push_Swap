/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:23:02 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/13 10:13:20 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest_in_bucket(t_list *stack)
{
	int	max = ft_lstsize(stack) - 1;
	int	found = stack->index;
	int	forward = 0;
	int back = 0;

	while (stack)
	{
		found = stack->index;
		stack = stack->next;
		if (found == max)
			break ;
		forward++;
	}
	back = (max + 1) - forward;
	if (back < forward)
		return (back * -1);
	return (forward);
}

static void	sort_in_buckets(t_pushswap *data)
{
	int	pos;

	while (data->stack_b)
	{
		pos = find_biggest_in_bucket(data->stack_b);
		if (pos > 0)
			multi_rotations(data, pos);
		else if (pos < 0)
			reverse_multi_rotations(data, pos);
		push_a(data);
	}
}

void	bucket_sort(t_pushswap *data)
{
	bucket_init(data);
	push_into_buckets(data);
	// print_bench(data);
	sort_in_buckets(data);
	// print_stacks(data, PRINT_NB | PRINT_IDX | PRINT_BUCKET | PRINT_INSTRUCTIONS);
	print_bench(data);
}
