/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:06:09 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/04 10:04:13 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexa(unsigned long n, char *base, t_frm *a)
{
	if (n >= 16)
		puthexa(n / 16, base, a);
	a->written += write(1, &base[n % 16], 1);
}

static void	putptr(void *ptr, t_frm *a)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		a->written += write(1, "(nil)", ft_strlen("(nil)"));
		return ;
	}
	a->written += write(1, "0x", 2);
	puthexa(addr, "0123456789abcdef", a);
}

void	formating_hexa(const char *str, va_list arg, t_frm *a)
{
	void			*ptr;
	unsigned int	hexa;

	if (str[a->index] == 'x' || str[a->index] == 'X')
	{
		hexa = (unsigned int)va_arg(arg, unsigned int);
		if (str[a->index] == 'x')
			puthexa(hexa, "0123456789abcdef", a);
		if (str[a->index] == 'X')
			puthexa(hexa, "0123456789ABCDEF", a);
		return ;
	}
	if (str[a->index] == 'p')
	{
		ptr = (void *)va_arg(arg, void *);
		putptr(ptr, a);
	}
}
