/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:32:26 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/03 09:54:26 by arbernad         ###   ########.fr       */
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

void	print_stacks(t_pushswap *data)
{
	t_list	*stack;

	printf("\n===== STACKS =====");
	stack = data->stack_a;
	printf("Stack A:\n");
	while (stack)
	{
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
	printf("\n");

	stack = data->stack_b;
	printf("Stack B:\n");
	while (stack)
	{
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
	printf("\n");

}
