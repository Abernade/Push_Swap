/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:43:23 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/23 11:21:08 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	unsigned int	size;

	size = ft_lstsize(lst);
	while (size > 1)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}
