/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:59:19 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/16 11:43:40 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_format
{
	size_t			index;
	size_t			written;
}	t_frm;

int		ft_printf(const char *str, ...);

/* ================== formating functions =============== */
void	formating_chars(const char *str, va_list list, t_frm *a);
void	formating_nb(const char *str, va_list arg, t_frm *a);
void	formating_hexa(const char *str, va_list arg, t_frm *a);

#endif
