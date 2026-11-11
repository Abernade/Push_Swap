/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:26:50 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/09 14:02:27 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool start_algorithm(t_config *flags, t_list *stack_a)
{
	if (flags->flag_adaptative)
		adaptative_a();
	else if (flags->flag_simple)
		simple_a(stack_a);
	else if(flags->flag_medium)
		medium_a();
	else if (flags->flag_complex)
		complex_a();

}
