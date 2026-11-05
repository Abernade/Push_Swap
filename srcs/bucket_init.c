/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 09:24:17 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/04 15:05:55 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bucket_init(t_pushswap *data)
{
	t_list	*node;
	int		bucket_count;

	indexer(data->stack_a);
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
