/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 08:50:00 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/12 08:57:33 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_index(t_list *a)
{
	int	min;

	min = a->index;
	while (a)
	{
		if (min > a->index)
			min = a->index;
		a = a->next;
	}
	return (min);
}

int	search_max_index(t_list *a)
{
	int	max;

	max = a->index;
	while (a)
	{
		if (max < a->index)
			max = a->index;
		a = a->next;
	}
	return (max);
}
