/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:04:03 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/31 11:06:23 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putint(int n, t_frm *a)
{
	char	temp;

	if (n == -2147483648)
	{
		a->written += write(1, "-2147483648", ft_strlen("-2147483648"));
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		a->written += write(1, "-", 1);
	}
	if (n >= 10)
		ft_putint(n / 10, a);
	temp = n % 10 + '0';
	a->written += write(1, &temp, 1);
}

static void	ft_putuint(unsigned int n, t_frm *a)
{
	char	temp;

	if (n >= 10)
		ft_putuint(n / 10, a);
	temp = n % 10 + '0';
	a->written += write(1, &temp, 1);
}

void	formating_nb(const char *str, va_list arg, t_frm *a)
{
	unsigned int		nb;

	if (str[a->index] == 'd' || str[a->index] == 'i')
	{
		nb = (int)va_arg(arg, int);
		ft_putint(nb, a);
		return ;
	}
	if (str[a->index] == 'u')
	{
		nb = (unsigned int)va_arg(arg, unsigned int);
		ft_putuint(nb, a);
		return ;
	}
}
