/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:14:14 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/04 17:44:18 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bucket_offset_forward(t_list *stack, int bucket, int position)
{
	t_list	*tmp;
	int		offset;

	offset = 0;
	while (stack && stack->bucket != bucket)
	{
		stack = lstnnext(stack, 1);
		offset++;
	}
	if (stack && !(position & TOP))
	{
		tmp = stack;
		while (stack->bucket == bucket)
		{
			stack = lstnnext(stack, 1);
			if (stack == tmp)
				return (0);
			offset++;
		}
	}
	return (offset);
}

static int	bucket_offset_backward(t_list *stack, int bucket, int position)
{
	t_list	*tmp;
	t_list	*prev;
	int		offset;

	offset = 0;
	prev = lstnprev(stack, 1);
	while (stack && prev->bucket != bucket)
	{
		prev = lstnprev(prev, 1);
		offset--;
	}
	if (stack && !(position & BOTTOM))
	{
		tmp = prev;
		while (prev->bucket == bucket)
		{
			prev = lstnprev(stack, 1);
			if (prev == tmp)
				return (0);
			offset--;
		}
	}
	return (offset);
}

void	push_to_bucket(t_pushswap *data, int bucket, int pos)
{
	int	offset_forward;
	int	offset_backward;

	offset_forward = bucket_offset_forward(data->stack_b, bucket, pos);
	offset_backward = bucket_offset_backward(data->stack_b, bucket, pos);
	if (ft_abs(offset_forward) <= ft_abs(offset_backward))
	{
		while (offset_forward)
		{
			rotate_b(data);
			offset_forward--;
		}
	}
	else
	{
		while (offset_backward)
		{
			reverse_rotate_b(data);
			offset_backward++;
		}
	}
	push_b(data);
}
