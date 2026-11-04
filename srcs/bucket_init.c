/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 09:24:17 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/04 10:16:58 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int nb)
{
	int	max;
	int	min;
	int	result;

	max = 46341;
	min = 0;
	result = max / 2;
	while (result * result != nb && max - min > 1)
	{
		if (result * result > nb)
		{
			max = result;
			result -= (result - min) / 2;
		}
		else
		{
			min = result;
			result += (max - result) / 2;
		}
	}
	if (result * result > nb)
		result--;
	return (result);
}

void	bucket_init(t_pushswap *data)
{
	t_list	*node;
	int		bucket_count;

	bucket_count = ft_sqrt(ft_lstsize(data->stack_a));
	if (bucket_count == 0)
		bucket_count = 1;
	node = data->stack_a;
	while (node)
	{
		node->bucket = node->index / bucket_count;
		node = node->next;
	}
}
