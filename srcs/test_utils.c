/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:32:26 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/10 15:27:25 by arbernad         ###   ########.fr       */
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

/**
 * Debug function
 * Flags:
 * 	PRINT_NB, print element number
 * 	PRINT_IDX, print element index
 * 	PRINT_BUCKET, print element bucket number
 * 	PRINT_INSTRUCTIONS, print the instruction list after printing the stacks
 */
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
			printf("bucket:\t%d\t\t", stack->bucket);
		if (bitflags & PRINT_PREVISION_A)
		{
			printf("\n-prev:\n\ttotal:\t%d", stack->prevision.total);
			printf("\tra: %d\t", stack->prevision.rt_a);
			printf("\t\trb: %d\t", stack->prevision.rt_b);
			printf("\t\trra: %d\t", stack->prevision.revrt_a);
			printf("\t\trrb: %d", stack->prevision.revrt_b);
		}
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
			printf("bucket:\t%d\t\t", stack->bucket);
		if (bitflags & PRINT_PREVISION_B)
		{
			printf("\n\t-prev:\n\ttotal:\t%d", stack->prevision.total);
			printf("\t\tra:\t%d\t\t", stack->prevision.rt_a);
			printf("\t\trb:\t%d\t\t", stack->prevision.rt_b);
			printf("\t\trra:\t%d\t\t", stack->prevision.revrt_a);
			printf("\t\trrb:\t%d\t\t", stack->prevision.revrt_b);
		}
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
