/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_prevision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:49:00 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/10 17:23:23 by arbernad         ###   ########.fr       */
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

int		get_target_offset(t_list *stack_b, int bucket, int target)
{
	int	flag;
	int	offset_forward;
	int	offset_backward;

	if (target == bucket || bucket == -1)
		flag = ANY;
	else if (target > bucket)
		flag = BOTTOM;
	else
		flag = TOP;
	offset_forward = bucket_offset_forward(stack_b, target, flag);
	offset_backward = bucket_offset_backward(stack_b, target, flag);
	if (ft_abs(offset_forward) <= ft_abs(offset_backward))
		return (offset_forward);
	else
		return (offset_backward);
}

static t_ops	prevision(t_list *stack_b, int target, int flags, int pos)
{
	int		offset_f;
	int		offset_b;
	t_ops	ops;

	ft_bzero(&ops, sizeof(t_ops));
	offset_f = bucket_offset_forward(stack_b, target, flags);
	offset_b = bucket_offset_backward(stack_b, target, flags);
	if (pos > 0)
		ops.rt_a = ft_abs(pos);
	else
		ops.revrt_a = ft_abs(pos);
	if (ft_abs(pos + offset_b) <= ft_abs(pos + offset_f))
		ops.revrt_b = ft_abs(offset_b);
	else
		ops.rt_b = ft_abs(offset_f);
	ops.total = max(ops.rt_a, ops.rt_b) + max(ops.revrt_a, ops.revrt_b);
	return (ops);
}

t_ops	get_prevision(t_pushswap *data, int bucket, int starting_pos)
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
	op1 = prevision(data->stack_b, target_bucket, flag, starting_pos);
	starting_pos -= data->a_size;
	op2 = prevision(data->stack_b, target_bucket, flag, starting_pos);
	if (op1.total < op2.total)
		return (op1);
	return (op2);
}
