/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:32:26 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/03 10:03:56 by arbernad         ###   ########.fr       */
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

void	print_instruction_list(t_pushswap *data)
{
	t_list	*instr;

	printf("\n===== INSTRUCTIONS =====\n\n");
	instr = data->instructions;
	while (instr)
	{
		printf("%s\n", (char *)instr->content);
		instr = instr->next;
	}
}

void	print_stacks(t_pushswap *data)
{
	t_list	*stack;

	printf("\n===== STACKS =====\n\n");
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
