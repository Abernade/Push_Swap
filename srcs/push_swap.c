/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/05 11:22:49 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_config	*config_init()
{
	t_config	*config;

	config = (t_config *)malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	config->flag_adaptative = 0;
	config->flag_bench = 0;
	config->flag_complex = 0;
	config->flag_medium = 0;
	config->flag_simple = 0;
	config->disorder = -1;
	return (config);
}

static t_pushswap	*pushswap_init()
{
	t_pushswap	*data;

	data = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!data)
		return (NULL);
	ft_bzero(data, sizeof(t_pushswap));
	data->config = config_init();
	if (!data->config)
	{
		free(data);
		return (NULL);
	}
	return (data);
}

static void	free_all(t_pushswap *data)
{
	free(data->config);
	ft_lstclear(&data->stack_a, &del_list);
	ft_lstclear(&data->stack_b, &del_list);
	ft_lstclear(&data->instructions, &del_list);
	free(data);
}

/*static void	algo_adaptator(swap *flags)
{
	if (flags->flag_adaptative)
		adaptative();
	else if (flags->flag_simple)
		simple();
	else if(flags->flag_medium)
		medium();
	else if (flags->flag_complex)
		complex();
}*/

int	main(int argc, char **av)
{
	t_pushswap		*data;
	unsigned int	size;

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
	size = ft_lstsize(data->stack_a);
	data->config->disorder = disorder(data->stack_a, size);

	bucket_sort(data);
	print_stacks(data, PRINT_NB | PRINT_IDX | PRINT_BUCKET);

	free_all(data);
	return (0);
}
