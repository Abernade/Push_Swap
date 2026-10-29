/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:38:20 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/26 17:05:45 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
			in_word = 1;
		if ((s[i] == c || s[i + 1] == '\0') && in_word == 1)
		{
			count++;
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static char	*word_dupp(char const *s, char c)
{
	int		i;
	size_t	len;
	char	*dest;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	free_all(char **ret, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

static char	**get_words(int words, char **ret, const char *s, char c)
{
	int	j;

	j = 0;
	while (j < words)
	{
		while (*s && *s == c)
			s++;
		ret[j] = word_dupp(s, c);
		if (!ret[j])
		{
			free_all(ret, j);
			return (NULL);
		}
		j++;
		while (*s && *s != c)
			s++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ret = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	ret = get_words(words, ret, s, c);
	return (ret);
}
