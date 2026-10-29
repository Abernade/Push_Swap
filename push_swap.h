/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:32:21 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/29 10:01:16 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef enum
{
	FALSE = 0,
	TRUE
}	t_bool;

typedef struct	s_swap
{
	int	flag_simple;
	int	flag_medium;
	int	flag_complex;
	int	flag_adaptative;
	int	flag_bench;
} swap;

#endif
