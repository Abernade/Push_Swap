/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:57:33 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/16 13:26:34 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static int	count_bits(int nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb = nb >> 1;
		count++;
	}
	return (count);
}

static int	find_bit(int nb, int pos)
{
	int	n;

	n = nb;
	if (n & (1 << (pos - 1)))
		return (1);
	return (0);
}

static void	alternate_a(t_pushswap *data, int bit)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(data->stack_a);
	while (i < len && data->stack_a)
	{
		if ((find_bit(data->stack_a->index, bit) & 1) == 0)
			push_b(data);
		else
			rotate_a(data);
		i++;
	}
}

static void	alternate_b(t_pushswap *data, int bit)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstsize(data->stack_b);
	while (i < len && data->stack_b)
	{
		if (find_bit(data->stack_b->index, bit) == 1)
			push_a(data);
		else if (find_bit(data->stack_b->index, bit) == 0)
			rotate_b(data);
		i++;
	}
}

static void	back_to_a(t_pushswap *data)
{
	while(data->stack_b)
		push_a(data);
}

void	radix(t_pushswap *data)
{
	int	max;
	int	bit;

	bit = 0;
	indexer(data);
	print_stacks(data, PRINT_NB | PRINT_IDX);
	max = search_max_index(data->stack_a);
	max = count_bits(max);
	while (bit <= max)
	{
		alternate_a(data, bit);
		alternate_b(data, bit + 1);
		bit++;
	}
	back_to_a(data);
}
