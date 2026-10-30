/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:46:28 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/26 17:06:14 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*curr;

	if (!del || !lst)
		return ;
	curr = *lst;
	while (curr)
	{
		p = curr->next;
		ft_lstdelone(curr, del);
		curr = p;
	}
	*lst = NULL;
}
