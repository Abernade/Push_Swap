/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/02 08:25:53 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flag_init(t_config *flags)
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

/*static void	algo_adaptator(swap *flags)
{
	if (flags->flag_adaptative)
		adaptative();
	else if (flags->flag_simple)
		simple();
	else if(flags->flag_medium)
		medium();
	else if (flags->flag_complex)
		complex();
}*/

static void	del_list(void *content)
{
	if (content)
		free(content);
}

int	main(int argc, char **av)
{
	t_config		flags;
	t_list			*new;
	unsigned int	size;

	flag_init(&flags);
	if (argc < 2)
		return (1);
	new = parser(av, argc, &flags);
	if (!new)
		return (1);
	if (has_flag_error(&flags))
	{
		printf("flag error\n");
		msg_error();
	}
	if (has_duplicate(new))
	{
		printf("duplicate error\n");
		msg_error();
	}
	size = ft_lstsize(new);
	flags.disorder = disorder(new, size);
	print_config(&flags);
	print_stack(new);
	ft_lstclear(&new, del_list);
	return (0);
}
