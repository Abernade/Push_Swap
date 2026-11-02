/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:26:38 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/02 10:33:55 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack)
{
	t_list	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	second_node = (*stack)->next;
	(*stack)->next = second_node->next;
	second_node->next = *stack;
	*stack = second_node;
}
