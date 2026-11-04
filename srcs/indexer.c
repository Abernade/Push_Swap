/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:45:55 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/03 11:43:41 by arbernad         ###   ########.fr       */
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

static t_list	*get_smallest(t_list *stack)
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

void	indexer(t_list *stack)
{
	t_list			*smallest;
	unsigned int	lst_size;
	unsigned int	i;

	init_indexes(stack);
	lst_size = ft_lstsize(stack);
	i = 0;
	while (i < lst_size)
	{
		smallest = get_smallest(stack);
		if (!smallest)
		{
			printf("\nINDEXER ERROR :c\n\n");
			return ;
		}
		smallest->index = i;
		i++;
	}
}
