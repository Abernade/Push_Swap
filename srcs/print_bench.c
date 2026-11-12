/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:50:00 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/12 12:24:19 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_pushswap *data)
{
	float	left;
	int		decimal;

	decimal = (int)(data->config->disorder * 100);
	left = ((data->config->disorder * 100) - decimal) * 100;
	printf("[bench] disorder:  %d.%d%%\n", decimal, (int)left);
}

static void	print_strategy(t_pushswap *data)
{
	write(1, "[bench] ", 7);
	if (data->config->flag_simple)
		write(1, "strategy : Simple / O(n^2)", 26);
	else if (data->config->flag_medium)
		write(1, "startegy : Medium / O(n√n)", 26);
	else if (data->config->flag_adaptative)
		write(1, "strategy : Complex / O(n log n)", 31);
	else
	{
		write(1, " strategy : Adaptative ", 24);
		if (data->config->flag_simple)
			write(1, "O(n^2)", 7);
		else if (data->config->flag_medium)
			write(1, "O(n√n)", 7);
		else if (data->config->flag_adaptative)
			write(1, "O(n log n)", 10);
	}
	write(1, "\n", 1);
}

static void	count_ops(t_list *instructions, t_ops *counts)
{
	char	*curr;

	while (instructions)
	{
		curr = (char *)instructions->content;
		if (ft_strcmp(curr, "sa") == 0)
			counts->sw_a++;
		else if (ft_strcmp(curr, "sb") == 0)
			counts->sw_b++;
		else if (ft_strcmp(curr, "pa") == 0)
			counts->psh_a++;
		else if (ft_strcmp(curr, "pb") == 0)
			counts->psh_b++;
		else if (ft_strcmp(curr, "ra") == 0)
			counts->rt_a++;
		else if (ft_strcmp(curr, "rb") == 0)
			counts->rt_b++;
		else if (ft_strcmp(curr, "rra") == 0)
			counts->revrt_a++;
		else if (ft_strcmp(curr, "rrb") == 0)
			counts->revrt_b++;
		/*else if (ft_strcmp(curr, "ss") == 0)
		else if (ft_strcmp(curr, "rr") == 0)
		else if (ft_strcmp(curr, "rrr") == 0)*/
		counts->total++;
		instructions = instructions->next;
	}
}

void	init_t_ops(t_ops *ops)
{
	ops->psh_a = 0;
	ops->psh_b = 0;
	ops->revrt_a = 0;
	ops->revrt_b = 0;
	ops->rt_a = 0;
	ops->rt_b = 0;
	ops->sw_a = 0;
	ops->sw_b = 0;
	ops->total = 0;
}

void	print_bench(t_pushswap *data)
{
	t_ops			ops;

	print_disorder(data);
	print_strategy(data);
	init_t_ops(&ops);
	count_ops(data->instructions, &ops);
	printf("[bench] total_ops: %d\n", ops.total);
	printf("[bench] sa: %d sb: %d ss: %%", ops.sw_a, ops.sw_b);
	printf(" pa: %d pb: %d\n", ops.psh_a, ops.psh_b);
	printf("[bench] ra: %d rb: %d rr: %%", ops.rt_a, ops.rt_b);
	printf(" rra: %d rrb: %d rrr: %%\n", ops.revrt_a, ops.revrt_b);
}
