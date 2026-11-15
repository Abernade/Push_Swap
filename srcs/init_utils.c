/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:28:45 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/13 16:29:21 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_config	*config_init()
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

t_pushswap	*pushswap_init()
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
