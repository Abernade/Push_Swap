/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 17:25:20 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/27 09:28:42 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	j;
	size_t	length;

	if (!dest)
		dest = "";
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (size + ft_strlen(src));
	length = len_dest + ft_strlen(src);
	j = 0;
	if (size == 0)
		size = 1;
	while (src[j] && j + len_dest < size - 1)
	{
		dest[len_dest + j] = src[j];
		j++;
	}
	if (j + len_dest < size)
		dest[len_dest + j] = '\0';
	return (length);
}
