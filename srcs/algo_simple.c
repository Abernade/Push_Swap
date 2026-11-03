/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 08:31:10 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/03 11:22:58 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	searchinl(t_list *stack_a, int index)
{
	int	i;
	int	*content;

	i = 0;
	while (i < index && stack_a)
	{
		stack_a = stack_a->next;
		i++;
	}
	content = (int *)stack_a->content;
	return (content[0]);
}

static int	first_value_gestion(t_pushswap *data)
{
	int	a;
	int a1;

	a = searchinl(data->stack_a, 0);
	a1 = searchinl(data->stack_a, 1);
	if (a > a1)
	{
		swap_a(data);
		rotate_a(data);
		rotate_a(data);
		return (2);
	}
	rotate_a(data);
	return (1);
}

static void	rotate_n_times(t_pushswap *data, int n)
{
	while (n > 0)
	{
		rotate_a(data);
		n--; //y a moyen qu'il ait un soucis dans la boucle
	}
}

t_list	*simple_a(t_pushswap *data, int size)
{
	int		i;
	int		sorted;
	int		a;
	int 	a1;

	sorted = first_value_gestion(data);
	while (sorted < size)
	{
		i = 0;
		push_b(data);
		while (i < sorted)
		{
			a = searchinl(data->stack_a, size - 2);
			a1 = searchinl(data->stack_b, 0);
			if (a > a1){
				reverse_rotate_a(data);
			}
			else
				break ;
			i++;
		}
		push_a(data);
		sorted++;
		rotate_n_times(data, i + 1);
	}
	return (data->stack_a);
}
