/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:50:00 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/04 11:18:30 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_pushswap *data)
{
	float left;

	write(1, "disorder : ", 11);
	data->config->disorder *= 100;
	left = (data->config->disorder - (int)data->config->disorder) * 100;
	write(1, ft_itoa((int)data->config->disorder), 2);
	write(1, ".", 1);
	write(1, ft_itoa(left), 2);
}

static void	print_strategy(t_pushswap *data)
{
	if (data->config->flag_simple)
		write(1, "strategy : simple / O(n^2)", 26);
	else if (data->config->flag_medium)
		write(1, "startegy : medium / O(n√n)", 26);
	else if (data->config->flag_adaptative)
		write(1, "strategy : complex / O(n log n)", 31);
	else if (data->config->flag_adaptative)
	{

	}
}

void	print_bench(t_pushswap *data)
{
	int	written_lines;

	written_lines = 0;
	while (written_lines < 5)
	{
		write(1, "[bench] ", 7);
		written_lines++;
		print_disorder(data);
		print_strategy(data);
	}
}
