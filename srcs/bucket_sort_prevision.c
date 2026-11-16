/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_prevision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:49:00 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/16 15:48:01 by arbernad         ###   ########.fr       */
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

static t_ops	prevision_b_to_a(t_list *stack_b, int target, int flags, int pos)
{
	int		offset_f;
	int		offset_b;
	int		offset;
	t_ops	ops;

	ft_bzero(&ops, sizeof(t_ops));
	offset_f = bucket_offset_forward(stack_b, target, flags);
	offset_b = bucket_offset_backward(stack_b, target, flags);
	if (ft_abs(offset_f) < ft_abs(offset_b))
		offset = offset_f;
	else
		offset = offset_b;
	if (pos >= 0)
		ops.rt_a = pos;
	else
		ops.revrt_a = -pos;
	if (offset >= 0)
		ops.rt_b = offset;
	else
		ops.revrt_b = -offset;
	ops.total = max(ops.rt_a, ops.rt_b) + max(ops.revrt_a, ops.revrt_b);
	return (ops);
}

static t_ops	prevision_a_to_b(t_pushswap *data, int idx, int starting_pos)
{

}

t_ops	get_b_to_a_prevision(t_pushswap *data, int idx, int starting_pos)
{
	t_list	*node;
	t_ops	op1;
	t_ops	op2;

	op1 = prevision_a_to_b(data, idx, starting_pos);
}

t_ops	get_a_to_b_prevision(t_pushswap *data, int bucket, int starting_pos)
{
	t_ops	op1;
	t_ops	op2;
	int		target_bucket;
	int		flag;

	target_bucket = get_target_bucket(data->stack_b, bucket);
	if (target_bucket == bucket || bucket == -1)
		flag = ANY;
	else if (target_bucket > bucket)
		flag = BOTTOM;
	else
		flag = TOP;
	op1 = prevision_b_to_a(data->stack_b, target_bucket, flag, starting_pos);
	starting_pos -= data->a_size;
	op2 = prevision_b_to_a(data->stack_b, target_bucket, flag, starting_pos);
	if (op1.total <= op2.total)
		return (op1);
	return (op2);
}
