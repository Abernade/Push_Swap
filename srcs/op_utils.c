/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:51:57 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/16 10:18:53 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_instr_str(int instr)
{
	char	*str = NULL;

	str = NULL;
	if (instr == SA)
		str = ft_strdup("sa");
	else if (instr == SB)
		str = ft_strdup("sb");
	else if (instr == PA)
		str = ft_strdup("pa");
	else if (instr == PB)
		str = ft_strdup("pb");
	else if (instr == RA)
		str = ft_strdup("ra");
	else if (instr == RB)
		str = ft_strdup("rb");
	else if (instr == RR)
		str = ft_strdup("rr");
	else if (instr == RRA)
		str = ft_strdup("rra");
	else if (instr == RRB)
		str = ft_strdup("rrb");
	else if (instr == RRR)
		str = ft_strdup("rrr");
	return (str);
}

// returns 0 on success, returns 1 on malloc error
int	add_instr(t_list **instructions, int instr)
{
	t_list	*node;
	char	*str;

	str = get_instr_str(instr);
	if (!str)
		return (1);
	node = ft_lstnew(str);
	if (!node)
		return (1);
	ft_lstadd_back(instructions, node);
	return (0);
}

void multi_rotations(t_pushswap *data, int rotations, char stack)
{
	while (rotations > 0)
	{
		if (stack == 'a')
			rotate_a(data);
		if (stack == 'b')
			rotate_b(data);
		rotations--;
	}
}

void reverse_multi_rotations(t_pushswap *data, int rotations, char stack)
{
	while (rotations < 0)
	{
		if (stack == 'b')
			reverse_rotate_b(data);
		if (stack == 'a')
			reverse_rotate_a(data);
		rotations++;
	}
}

t_bool	is_rotation_str(char *str)
{
	if (!ft_strcmp(str, "ra")
		|| !ft_strcmp(str, "rb")
		|| !ft_strcmp(str, "rra")
		|| !ft_strcmp(str, "rrb")
		|| !ft_strcmp(str, "rr")
		|| !ft_strcmp(str, "rrr"))
		return (TRUE);
	return (FALSE);
}
