/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 08:31:10 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/02 17:38:29 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		searchinl(t_list *stack_a, int index)
{
	int	i;
	int	*content;
	t_list	*head;

	i = 0;
	head = stack_a;
	while (i < index && stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	content = (int *)stack_a->content;
	return (content[0]);
}

t_list	*simple_a(t_pushswap *data, int size)
{
	int		i;
	int		sorted;
	int		index;

	sorted = 0;
	while (data->stack_a)
	{
		if (sorted == 0)
		{
			if () //add condition if first is higher than second then swap and sorted == 2 and rotate 2 times
			//else
				rotate_a(data);
				sorted++;
		}
		while (sorted < size)
		{
			i = 0;
			push_b(data);
			while(i < sorted)
			{
				index = size - sorted + 1;
				if (searchinl(data->stack_a, size - 1) > searchinl(data->stack_a, 1))
					rotate_a(data);
				i++;
			}
			push_a(data);
			sorted++;
		}
		//here need to rotate back
	}
	return (data->stack_a);
}
