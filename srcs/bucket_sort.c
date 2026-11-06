/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:23:02 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/06 10:57:45 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_bucket(t_list *stack, int bucket)
{
	int	closest;

	closest = -1;
	while (stack)
	{
		if (stack->bucket == bucket)
			return (bucket);
		else if (ft_abs(stack->bucket - bucket) < ft_abs(closest - bucket)
				|| closest == -1)
		{
			closest = stack->bucket;
		}
		stack = stack->next;
	}
	return (closest);
}

static void	push_into_buckets(t_pushswap *data)
{
	int	bucket;
	int	flag;

	while (data->stack_a)
	{
		bucket = get_target_bucket(data->stack_b, data->stack_a->bucket);
		if (bucket == data->stack_a->bucket)
			flag = ANY;
		else if (bucket > data->stack_a->bucket)
			flag = BOTTOM;
		else
			flag = TOP;
		push_to_bucket(data, bucket, flag);
		print_stacks(data, PRINT_NB | PRINT_IDX | PRINT_BUCKET);
	}
}

static int	find_biggest_in_bucket(t_list *stack)
{
	int	max = ft_lstsize(stack) - 1;
	int	found = stack->index;
	int	forward = 0;
	int back = 0;

	printf("\nmax size of stack = [%d]\n", max);
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
		print_stacks(data, PRINT_NB | PRINT_IDX | PRINT_BUCKET);
	}
}

void	bucket_sort(t_pushswap *data)
{
	bucket_init(data);
	push_into_buckets(data);
	sort_in_buckets(data);
}
