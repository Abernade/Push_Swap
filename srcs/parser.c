/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:30 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/29 11:35:19 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_flags(char *str, swap *flags, size_t len)
{
	if (ft_memcmp(str, "--bench", len + 1))
		flags->flag_bench = 1;
	else if (ft_memcmp(str, "--simple", len + 1))
		flags->flag_simple = 1;
	else if (ft_memcmp(str, "--medium", len + 1))
		flags->flag_medium = 1;
	else if (ft_memcmp(str, "--complex", len + 1))
		flags->flag_complex = 1;
	else if (ft_memcmp(str, "--adaptative", len + 1))
		flags->flag_adaptative = 1;
}

static int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static t_list	*get_ints(char **av, int argc)
{
	int		i;
	int		*converted;
	t_list	*head;
	t_list	*new;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		if (!str_is_digit(*av))
		{
			ft_lstclear(&head, del_list);
			return (NULL);
		}
		converted = (int *)malloc(sizeof(int));
		converted[0] = ft_atoi(*av);
		new = ft_lstnew(converted);
		ft_lstadd_back(&head, new);
		av++;
		i++;
	}
	return (head);
}

t_list	*parser(char **av, int argc, swap *flags)
{
	int		i;
	t_list	*head;
	t_list	*new;

	i = 1; //on veux pas l'exec
	av++;
	set_flags(*av, flags, ft_strlen(*av));
	head = get_ints(av, argc);
	return (head);
}
