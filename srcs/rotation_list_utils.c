/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:41:32 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/15 16:06:04 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_reverse_rotations(t_list **lst, t_ops *rotations)
{
	while (rotations->revrt_ab)
	{
		if (add_instr(lst, RRR))
			return (1);
		rotations->revrt_ab--;
	}
	while (rotations->revrt_a)
	{
		if (add_instr(lst, RRA))
			return (1);
		rotations->revrt_a--;
	}
	while (rotations->revrt_b)
	{
		if (add_instr(lst, RRB))
			return (1);
		rotations->revrt_b--;
	}
	return (0);
}

static int	add_rotations(t_list **lst, t_ops *rotations)
{
	while (rotations->rt_ab)
	{
		if (add_instr(lst, RR))
			return (1);
		rotations->rt_ab--;
	}
	while (rotations->rt_a)
	{
		if (add_instr(lst, RA))
			return (1);
		rotations->rt_a--;
	}
	while (rotations->rt_b)
	{
		if (add_instr(lst, RB))
			return (1);
		rotations->rt_b--;
	}
	return (0);
}

t_list	*create_rotation_list(t_ops *rotations)
{
	t_list	*lst;

	lst = NULL;
	if (add_rotations(&lst, rotations))
	{
		ft_lstclear(&lst, &del_list);
		return (NULL);
	}
	if (add_reverse_rotations(&lst, rotations))
	{
		ft_lstclear(&lst, &del_list);
		return (NULL);
	}
	return (lst);
}
