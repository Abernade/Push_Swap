/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:23:02 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/06 11:18:35 by arbernad         ###   ########.fr       */
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
		if (bucket == data->stack_a->bucket || bucket == -1)
			flag = ANY;
		else if (bucket > data->stack_a->bucket)
			flag = BOTTOM;
		else
			flag = TOP;
		push_to_bucket(data, bucket, flag);
		print_stacks(data, PRINT_NB | PRINT_IDX | PRINT_BUCKET);
	}
}

void	bucket_sort(t_pushswap *data)
{
	bucket_init(data);
	push_into_buckets(data);
}
