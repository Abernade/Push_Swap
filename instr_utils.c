/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:51:57 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/02 16:14:44 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_instr_str(int instr)
{
	char	*str;

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
	else if (instr == RRA)
		str = ft_strdup("rra");
	else if (instr == RRB)
		str = ft_strdup("rrb");
	if (!str)
		return (NULL);
	return (str);
}

// returns 0 on success, returns 1 on malloc error
int	add_instr(t_pushswap *data, int instr)
{
	t_list	*node;
	char	*str;

	str = get_instr_str(instr);
	if (!str)
		return (1);
	node = ft_lstnew(str);
	if (!node)
		return (1);
	ft_lstadd_back(&data->instructions, node);
	return (0);
}
