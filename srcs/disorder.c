/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:39:11 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/02 16:30:06 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		contentcmp(t_list *list_a, int i, int j)
{
	int		la;
	int		lb;

	if (!list_a)
		return (-1);
	j -= i;
	while (i > 0)
	{
		list_a = list_a->next;
		i--;
	}
	la = ((int *)list_a->content)[0];
	while (j > 0)
	{
		list_a = list_a->next;
		j--;
	}
	lb = ((int *)list_a->content)[0];
	if (la > lb)
		return (TRUE);
	return (FALSE);
}

double	disorder(t_list *list_a, unsigned int size)
{
	double				mistakes;
	double				total_pairs;
	unsigned int		i;
	unsigned int		j;

	if (size < 2)
		return (1.0f);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (contentcmp(list_a, i, j) == TRUE)
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes/total_pairs);
}
