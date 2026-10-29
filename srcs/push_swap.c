/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/29 10:10:21 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	flag_init(swap *flags)
{
	if (!flags)
		return ;
	flags->flag_adaptative = 0;
	flags->flag_bench = 0;
	flags->flag_complex = 0;
	flags->flag_medium = 0;
	flags->flag_simple = 0;
	flags->disorder = -1;
}

int	main(int argc, char **av)
{
	swap	flags;
	flag_init(&flags); //faire fonction à part pour
	if (argc < 2)// dans le cas ou on appelle que l'executable
		return (1);
	parser(av, argc, &flags);
	algo_adaptor(&flags);
}
