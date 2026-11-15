/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:55:22 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/11 17:27:52 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	max;
	int	min;
	int	result;

	max = 46341;
	min = 0;
	result = max / 2;
	while (result * result != nb && max - min > 1)
	{
		if (result * result > nb)
		{
			max = result;
			result -= (result - min) / 2;
		}
		else
		{
			min = result;
			result += (max - result) / 2;
		}
	}
	if (result * result > nb)
		result--;
	return (result);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
