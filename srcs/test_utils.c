/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:32:26 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/04 10:38:28 by arbernad         ###   ########.fr       */
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

void	print_stacks(t_pushswap *data, int bitflags)
{
	t_list	*stack;

	printf("\n===== STACKS =====\n\n");
	stack = data->stack_a;
	printf("Stack A:\n");
	while (stack)
	{
		if (bitflags & PRINT_NB)
			printf("nb:\t%d\t\t", *(int *)stack->content);
		if (bitflags & PRINT_IDX)
			printf("idx:\t%d\t\t", stack->index);
		if (bitflags & PRINT_BUCKET)
			printf("bucket:\t%d", stack->bucket);
		stack = stack->next;
		printf("\n");
	}
	printf("\n");

	stack = data->stack_b;
	printf("Stack B:\n");
	while (stack)
	{
		if (bitflags & PRINT_NB)
			printf("nb:\t%d\t\t", *(int *)stack->content);
		if (bitflags & PRINT_IDX)
			printf("idx:\t%d\t\t", stack->index);
		if (bitflags & PRINT_BUCKET)
			printf("bucket:\t%d", stack->bucket);
		stack = stack->next;
		printf("\n");
	}
	printf("\n");
	if (bitflags & PRINT_INSTRUCTIONS)
		print_instruction_list(data);
}

void	printf_stacks(t_pushswap *data)
{
	t_list	*head;

	head = data->stack_a;
	while (head)
	{
		printf("[%d]", *(int *)head->content);
		head = head->next;
	}
	printf("\n");
}
