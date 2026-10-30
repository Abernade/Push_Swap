/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:25:10 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/24 15:58:11 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		count++;
		nb = nb / 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*ret;
	long	nb;

	len = count_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	nb = n;
	i = 0;
	if (nb < 0)
		nb *= -1;
	while (i < len)
	{
		ret[len - i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	if (n < 0)
		ret[0] = '-';
	ret[len] = '\0';
	return (ret);
}
