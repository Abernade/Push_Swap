/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:39:11 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/29 11:55:29 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* faire fonction qui avance de 1 */

float	disorder(t_swap *list_a, unsigned int size)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size - 1)
		{
			total_pairs += 1;
			if (contentcmp(list_a))
				mistakes += 1;
		}
	}
	return (mistakes/total_pairs);
}
