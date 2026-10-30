/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/30 11:53:24 by vldryga          ###   ########.fr       */
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
	t_list			*head_new;
	unsigned int	size;

	flag_init(&flags);
	if (argc < 2)
		return (1);
	new = parser(av, argc, &flags);
	if (!new)
		return (1);
	head_new = new;
	while (head_new)
	{
		printf("[%d]\n", ((int *)head_new->content)[0]);
		head_new = head_new->next;
	}
	//error_check(&head_new);
	//algo_adaptator(&flags);
	size = ft_lstsize(new);
	flags.disorder = disorder(new, size);
	printf("[%f]\n", flags.disorder);
	ft_lstclear(&new, del_list);
	return (0);
}
