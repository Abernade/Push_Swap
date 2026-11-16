/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:45:55 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/16 13:42:41 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_indexes(t_list *stack)
{
	while (stack)
	{
		stack->index = -1;
		stack = stack->next;
	}
}

static t_list	*get_smallest_no_idx(t_list *stack)
{
	t_list	*smallest;

	smallest = NULL;
	while (stack)
	{
		if (stack->index == -1)
		{
			if (!smallest)
				smallest = stack;
			else if (*(int *)stack->content < *(int *)smallest->content)
				smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

t_list	*get_smallest(t_list *stack)
{
	t_list	*smallest;

	smallest = NULL;
	while (stack)
	{
		if (!smallest || *(int *)stack->content < *(int *)smallest->content)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	smallest_on_top(t_pushswap *data)
{
	t_list	*node;
	t_list	*smallest;
	int		forward_idx;
	int		backward_idx;

	smallest = get_smallest(data->stack_a);
	forward_idx = 0;
	backward_idx = 0;
	node = smallest;
	while (node->prev)
	{
		node = node->prev;
		forward_idx++;
	}
	while (smallest)
	{
		smallest = smallest->next;
		backward_idx++;
	}
	if (forward_idx <= backward_idx)
		multi_rotations(data, forward_idx, 'a');
	else
		reverse_multi_rotations(data, backward_idx, 'a');
}

void	indexer(t_pushswap *data)
{
	t_list			*smallest;
	unsigned int	lst_size;
	unsigned int	i;

	init_indexes(data->stack_a);
	lst_size = ft_lstsize(data->stack_a);
	i = 0;
	while (i < lst_size)
	{
		smallest = get_smallest_no_idx(data->stack_a);
		if (!smallest)
		{
			ft_printf("\nINDEXER ERROR :c\n\n");
			return ;
		}
		smallest->index = i;
		i++;
	}
}
