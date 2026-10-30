/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:45:51 by arbernad          #+#    #+#             */
/*   Updated: 2026/10/29 15:32:31 by arbernad         ###   ########.fr       */
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
		if (*content == *(int *)lst->content)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

t_bool	has_flag_error(t_config *config)
{
	int flag_count;

	flag_count = config->flag_adaptative;
	flag_count += config->flag_simple;
	flag_count += config->flag_medium;
	flag_count += config->flag_complex;
	if (flag_count > 1)
		return (TRUE);
	return (FALSE);
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
