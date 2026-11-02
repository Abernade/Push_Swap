/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:32:26 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/02 16:20:27 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_config(t_config *config)
{
	printf("flag_simple:\t%d\n", config->flag_simple);
	printf("flag_medium:\t%d\n", config->flag_medium);
	printf("flag_complex:\t%d\n", config->flag_complex);
	printf("flag_adaptative:\t%d\n", config->flag_adaptative);
	printf("flag_bench:\t%d\n", config->flag_bench);
	printf("disorder:\t%f\n\n", config->disorder);
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
}

void	printf_stacks(t_pushswap *data)
{
	t_list	*head;

	head = data->stack_a;
	while (data->stack_a)
	{
		printf("[%d]", *(int *)head->content);
		head = head->next;
	}
	printf("\n");
}
