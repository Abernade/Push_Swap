/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:14:14 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/11 11:27:58 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dist_from_bucket_bottom(t_list *stack, int bucket)
{
	t_list	*head;
	int		offset;

	if (stack->bucket != bucket)
		return (0);
	offset = 1;
	head = stack;
	stack = lstnnext(stack , 1);
	while (stack->bucket == bucket)
	{
		if (stack == head)
			return (0);
		stack = lstnnext(stack, 1);
		offset++;
	}
	return (offset);
}

static int	dist_from_bucket_top(t_list *stack, int bucket)
{
	t_list	*head;
	int		offset;

	if (lstnprev(stack, 1)->bucket != bucket)
		return (0);
	offset = -1;
	head = stack;
	stack = lstnprev(stack , 1);
	while (lstnprev(stack , 1)->bucket == bucket)
	{
		if (stack == head)
			return (0);
		stack = lstnprev(stack, 1);
		offset--;
	}
	return (offset);
}

int	bucket_offset_forward(t_list *stack, int bucket, int position)
{
	int		offset;

	offset = 0;
	while (stack && stack->bucket != bucket)
	{
		stack = lstnnext(stack, 1);
		offset++;
	}
	if (position == ANY || !stack)
		return (offset);
	if (position == BOTTOM)
		offset += dist_from_bucket_bottom(stack, bucket);
	else
		offset += dist_from_bucket_top(stack, bucket);
	return (offset);
}

int	bucket_offset_backward(t_list *stack, int bucket, int position)
{
	int		offset;

	offset = 0;
	while (stack && stack->bucket != bucket)
	{
		stack = lstnprev(stack, 1);
		offset--;
	}
	if (position == ANY || !stack)
		return (offset);
	if (position == BOTTOM)
		offset += dist_from_bucket_bottom(stack, bucket);
	else
		offset += dist_from_bucket_top(stack, bucket);
	return (offset);
}

void	push_to_bucket(t_pushswap *data, int bucket, int pos)
{
	int	offset_forward;
	int	offset_backward;
	int	offset;

	offset_forward = bucket_offset_forward(data->stack_b, bucket, pos);
	offset_backward = bucket_offset_backward(data->stack_b, bucket, pos);
	if (ft_abs(offset_forward) <= ft_abs(offset_backward))
		offset = offset_forward;
	else
		offset = offset_backward;
	while (offset > 0)
	{
		rotate_b(data);
		offset--;
	}
	while (offset < 0)
	{
		reverse_rotate_b(data);
		offset++;
	}
	push_b(data);
}
