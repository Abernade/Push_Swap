/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:36:06 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/26 09:01:01 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	ft_strlcat(ret, s1, len + 1);
	ft_strlcat(ret, s2, len + 1);
	return (ret);
}
