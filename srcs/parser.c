/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:10:30 by vldryga           #+#    #+#             */
/*   Updated: 2026/10/30 11:50:36 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	set_flags(char **str, t_config *flags, size_t len)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_memcmp(str[i], "--bench", len + 1))
			flags->flag_bench = 1;
		else if (ft_memcmp(str[i], "--simple", len + 1))
			flags->flag_simple = 1;
		else if (ft_memcmp(str[i], "--medium", len + 1))
			flags->flag_medium = 1;
		else if (ft_memcmp(str[i], "--complex", len + 1))
			flags->flag_complex = 1;
		else if (ft_memcmp(str[i], "--adaptative", len + 1))
			flags->flag_adaptative = 1;
		i++;
	}
	if (!has_flag_error(flags))
		return (FALSE);
	return (TRUE);
}

/*	normalement c'est corrigé : d'abord ca verif les espaces,
*	ensuite si y a un moins et enfin que la chaine n'est pas juste un moins;
*	j'hésite quand à savoir si on laisse l'espace parce qu'em théorie c'est
* 	pas nécessaire comme *	le partie pris est e ne pas accepter une entrée :
* 	>? ./push_swap <flags> "   454" "4" "-69 45 63"	*/
static int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}


static void	del_list(void *content)
{
	if (content)
		free(content);
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

t_list	*parser(char **av, int argc, t_config *flags)
{
	int		i;
	t_list	*head;

	i = 1; //on veux pas l'exec
	av++;
	if (set_flags(av, flags, ft_strlen(*av)))
		head = get_ints(av, argc);
	else
	{
		msg_error();
		return (NULL);
	}
	return (head);
}
