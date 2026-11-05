/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:05:19 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/04 17:46:00 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnnext(t_list *node, int offset)
{
	if (!node)
		return (NULL);
	while (offset)
	{
		if (node->next)
			node = node->next;
		else
			node = ft_lstfirst(node);
		offset--;
	}
	return (node);
}

t_list	*lstnprev(t_list *node, int offset)
{
	if (!node)
		return (NULL);
	while (offset)
	{
		if (node->prev)
			node = node->prev;
		else
			node = ft_lstlast(node);
		offset--;
	}
	return (node);
}
