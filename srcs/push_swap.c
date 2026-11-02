/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/02 11:34:29 by arbernad         ###   ########.fr       */
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

static void	del_list(void *content)
{
	if (content)
		free(content);
}

int	main(int argc, char **av)
{
	t_pushswap		*data;
	t_list			*new;
	unsigned int	size;

	if (argc < 2)
		return (1);
	data = pushswap_init();
	if (!data)
		return (1);
	new = parser(av, argc, data->config);
	if (!new)
		return (1);
	if (has_flag_error(data->config))
	{
		printf("flag error\n");
		msg_error();
	}
	if (has_duplicate(new))
	{
		printf("duplicate error\n");
		msg_error();
	}
	size = ft_lstsize(new);
	data->config->disorder = disorder(new, size);
	print_config(data->config);
	print_stack(new);
	ft_lstclear(&new, del_list);
	return (0);
}
