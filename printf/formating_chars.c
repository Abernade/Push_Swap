/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 11:08:05 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/31 11:10:38 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formating_chars(const char *str, va_list list, t_frm *a)
{
	const char	*stock;
	char		temp;

	stock = NULL;
	if (str[a->index] == 'c')
	{
		temp = (char)va_arg(list, int);
		a->written += write(1, &temp, 1);
		return ;
	}
	if (str[a->index] == 's')
	{
		stock = (const char *)va_arg(list, const char *);
		if (!stock)
		{
			a->written += write(1, "(null)", ft_strlen("(null)"));
			return ;
		}
		a->written += write(1, stock, ft_strlen(stock));
		return ;
	}
	a->written += write(1, "%", 1);
}
