/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/15 17:07:12 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_pushswap *data)
{
	free(data->config);
	ft_lstclear(&data->stack_a, &del_list);
	ft_lstclear(&data->stack_b, &del_list);
	ft_lstclear(&data->instructions, &del_list);
	free(data);
}

static void	start_sorting(t_pushswap *data, t_config *info)
{
	if (info->flag_adaptative)
	{
		if (info->disorder < 0.2)
			data->stack_a = insertion_sort(data, data->a_size);
		if (info->disorder <= 0.2 && info->disorder < 0.5)
			bucket_sort(data);
		if (info->disorder >= 0.5)
			turk_sort(data);
	}
	else if (info->flag_simple)
		data->stack_a = insertion_sort(data, data->a_size);
	else if (info->flag_medium)
		bucket_sort(data);
	else if (info->flag_complex)
		turk_sort(data);
}

int	main(int argc, char **av)
{
	t_pushswap		*data;

	if (argc < 2)
		return (1);
	data = pushswap_init();
	if (!data)
		return (1);
	data->stack_a = parser(av, data->config);
	if (!data->stack_a)
		return (1);
	if (has_flag_error(data->config))
	{
		msg_error();
		return (1);
	}
	if (has_duplicate(data->stack_a))
	{
		msg_error();
		return (1);
	}
	data->a_size = ft_lstsize(data->stack_a);
	data->b_size = 0;
	data->config->disorder = disorder(data->stack_a, data->a_size);
	start_sorting(data, data->config);
	turk_sort(data);
	optimize_rotations(&data->instructions);
	print_stacks(data, PRINT_INSTRUCTIONS);
	print_bench(data);
	free_all(data);
	return (0);
}
