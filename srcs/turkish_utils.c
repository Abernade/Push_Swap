/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 08:49:19 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/12 15:31:53 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_reverse_a(t_pushswap *data, t_ops *c)
{
	c->revrt_a = data->a_size - c->rt_a;
	c->rt_a = 0;
}

void	count_reverse_b(t_pushswap *data, t_ops *c)
{
	c->revrt_b = data->b_size - c->rt_b;
	c->rt_b = 0;
}

static int		count_total(t_ops *c)
{
	int max_rt;
	int	max_rvrt;
	int	total;

	max_rt = c->rt_a + c->rt_b - min(c->rt_a, c->rt_b);
	max_rvrt = c->revrt_a + c->revrt_b - min(c->revrt_a, c->revrt_b);
	total = max_rt + max_rvrt + 1;
	return (total);
}

static t_ops	*get_node(t_pushswap *data, int rot)
{
	t_list	*head;
	t_ops	*curr;

	head = data->stack_a;
	while (rot > 0)
	{
		rot--;
		head = head->next;
	}
	curr = &head->prevision;
	return (curr);
}

static void	init_info(t_pushswap *data, t_turk *info, int rot)
{
	t_list *head;

	head = data->stack_a;
	while (rot > 0)
	{
		rot--;
		head = head->next;
	}
	info->b_max = search_max_index(data->stack_b);
	info->b_min = search_min_index(data->stack_b);
	info->a_value = head->index;
	info->current = data->stack_b->index;
}

static int search_closest_index(t_list *a, int value)
{
	int min = 2147483647; //maybe need some change
	int	curr;
	int	ret;

	while (a)
	{
		curr = ft_abs(value - a->index);
		if (curr < min)
		{
			min = curr;
			ret = a->index;
		}
		a = a->next;
	}
	return (ret);
}

static void	fill_rotations(t_pushswap *data, t_ops *c, t_turk *info)
{
	int	closest;
	t_list	*a;

	closest = search_closest_index(data->stack_b, info->a_value);
	a = data->stack_b;
	while (closest != a->index)
	{
		c->rt_b++;
		info->current = a->index;
	}
	if (c->rt_a > (data->a_size / 2))
		count_reverse_a(data, c);
	if (c->rt_b > (data->b_size / 2))
		count_reverse_b(data, c);
	c->total = count_total(c);
}

int	count_moves_for_one(t_pushswap *data, t_turk *info, int rotations)
{
	t_list *head;
	int		count;
	t_ops	*c;

	c = get_node(data, rotations);
	init_info(data, info, rotations);
	head = data->stack_b;
	if (info->a_value > info->b_max)
	{
		c->psh_b++;
		return (1);
	}
	else if (info->a_value < info->b_min)
	{
		c->psh_b++;
		c->rt_b++;
		return (2);
	}
	c->rt_a = rotations;
	fill_rotations(data, c, info);
	return (count);
}
