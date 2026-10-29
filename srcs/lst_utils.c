/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:52:35 by arbernad          #+#    #+#             */
/*   Updated: 2026/10/29 10:09:49 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	is_duplicate(t_list *lst)
{
	int	*content;

	content = lst->content;
	lst = lst->next;
	while (lst)
	{

		lst = lst->next;
	}
}

t_bool	has_duplicate(t_list *lst)
{
	while (lst)
	{
		if (is_duplicate(lst))
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}
