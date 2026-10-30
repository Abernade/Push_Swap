/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:20:19 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/24 15:58:18 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	temp;

	len = ft_strlen(s) - 1;
	temp = c;
	if (temp == '\0')
		return ((char *)s + len + 1);
	while (len >= 0)
	{
		if (s[len] == temp)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
