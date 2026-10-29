/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:39:11 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/29 14:24:36 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/* faire fonction qui avance de 1 */

static int		contentcmp(t_list *list_a, int i, int j, int size)
{
	t_list	*list_b;
	t_list	*head;
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
	lb = ((int *)list_b->content)[0];
}

float	disorder(t_list *list_a, unsigned int size)
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
			if (contentcmp(list_a, i, j, size))
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes/total_pairs);
}
