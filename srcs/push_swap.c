/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:18 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/29 15:01:15 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	flag_init(t_swap *flags)
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
	//verifier qu'il n'y a pas pls flag => idee de faire une fct qui check les erreur
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
	t_swap	flags;
	t_list	*new;
	t_list	*head_new;
	unsigned int	size;

	flag_init(&flags); //faire fonction à part pour
	if (argc < 2)// dans le cas ou on appelle que l'executable
		return (1);
	new = parser(av, argc, &flags);
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
