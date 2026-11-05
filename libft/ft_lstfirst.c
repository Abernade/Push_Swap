/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:16:50 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/04 17:54:30 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstfirst(t_list *lst)
{
	printf("lst: %p\t\tprev: %p\n", lst, lst->prev);
	while (lst && lst->prev)
		lst = lst->prev;
	printf("returned %p\n", lst);
	return (lst);
}
