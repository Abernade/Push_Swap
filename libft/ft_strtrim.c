/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:37:15 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/26 17:05:52 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_trimmed(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	if (s1[start] == '\0')
		return (0);
	while (s1[end - 1] && is_in_set(s1[end - 1], set))
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;
	size_t	start;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	len = count_trimmed(s1, set);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	start = 0;
	i = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (i < len)
	{
		ret[i] = s1[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
