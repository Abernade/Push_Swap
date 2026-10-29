/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:27:49 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/22 09:07:50 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ii;
	size_t	l_len;

	i = 0;
	l_len = ft_strlen(little);
	if (l_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i])
	{
		ii = 0;
		while (little[ii] && big[i + ii] == little[ii] && ii + i < len)
		{
			if (little[ii + 1] == '\0')
				return ((char *)big + i);
			ii++;
		}
		i++;
	}
	return (NULL);
}
