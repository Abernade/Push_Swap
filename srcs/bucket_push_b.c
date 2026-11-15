/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_push_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:14:24 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/11 17:13:09 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_pushswap *data ,t_ops *rotations)
{
	while (rotations->rt_a)
	{
		rotate_a(data);
		rotations->rt_a--;
	}
	while (rotations->rt_b)
	{
		rotate_b(data);
		rotations->rt_b--;
	}
	while (rotations->revrt_a)
	{
		reverse_rotate_a(data);
		rotations->revrt_a--;
	}
	while (rotations->revrt_b)
	{
		reverse_rotate_b(data);
		rotations->revrt_b--;
	}
}

static void	push_fastest(t_pushswap *data)
{
	t_list	*node;
	t_ops	*fastest;

	fastest = NULL;
	node = data->stack_a;
	while (node)
	{
		if (!fastest || fastest->total > node->prevision.total)
			fastest = &node->prevision;
		node = node->next;
	}
	rotate(data, fastest);
	push_b(data);
	node = data->stack_a;
	while (node)
	{
		ft_bzero(&node->prevision, sizeof(t_ops));
		node = node->next;
	}
}

void	push_into_buckets(t_pushswap *data)
{
	t_list	*node;
	int		i;

	while(data->stack_a)
	{
		i = 0;
		node = data->stack_a;
		while (node)
		{
			node->prevision = get_prevision(data, node->bucket, i);
			node = node->next;
			i++;
		}
		// print_stacks(data, PRINT_IDX | PRINT_BUCKET | PRINT_PREVISION_A);
		push_fastest(data);
	}
}
