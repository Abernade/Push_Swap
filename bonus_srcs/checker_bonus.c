/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:35:51 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/13 16:59:54 by vldryga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_all(t_pushswap *data)
{
	free(data->config);
	ft_lstclear(&data->stack_a, &del_list);
	ft_lstclear(&data->stack_b, &del_list);
	ft_lstclear(&data->instructions, &del_list);
	free(data);
}

t_bool	is_an_instruction(char *str)
{
	if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb"))
		return (1);
	if (!ft_strcmp(str, "ra") || !ft_strcmp(str, "rb") || !ft_strcmp(str, "rr"))
		return (1);
	if (!ft_strcmp(str, "pa") || !ft_strcmp(str, "pb"))
		return (1);
	if (!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb") || !ft_strcmp(str, "rrr"))
		return (1);
	return (0);
}

static void	add_to_list(char *str, t_pushswap *data)
{
	if (!ft_strcmp(str, "sa"))
		add_instr(data, SA);
	if (!ft_strcmp(str, "sb"))
		add_instr(data, SB);
	if (!ft_strcmp(str, "ra"))
		add_instr(data, RA);
	if (!ft_strcmp(str, "rb"))
		add_instr(data, RB);
	if (!ft_strcmp(str, "rr"))
		add_instr(data, RR);
	if (!ft_strcmp(str, "pa"))
		add_instr(data, PA);
	if (!ft_strcmp(str, "pb"))
		add_instr(data, PB);
	if (!ft_strcmp(str, "rra"))
		add_instr(data, RRA);
	if (!ft_strcmp(str, "rrb"))
		add_instr(data, RRB);
	if (!ft_strcmp(str, "rrr"))
		add_instr(data, RRR);
}

static void parse_instructions(t_pushswap *data, char *str)
{
	int		i;
	char	**list_instr;

	i = 0;
	list_instr = ft_split(str, '\n');
	while (list_instr[i])
	{
		if (is_an_instruction(list_instr[i]))
			add_to_list(list_instr[i], data);
		else
		{
			if (data->instructions)
				free_all(data);
			printf("Error\n");
			return ;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_pushswap *data;
	int			browsed = 1;
	char 		buffer[BUFFER_SIZE + 1];
	char		*instr;

	if (ac < 2)
		return (1);
	data = pushswap_init();
	data->stack_a = parser(av, data->config);
	if (!data->stack_a)
		return (1);
	instr = NULL;
	while (browsed > 0)
	{
		browsed = read(1, buffer, BUFFER_SIZE);
		if (browsed > 0)
		{
			buffer[BUFFER_SIZE] = '\0';
			instr = ft_strjoin(instr, buffer);
		}
	}
	printf("instr [%s]", instr);
	parse_instructions(data, instr);
	if (!data->instructions)
	{
		free_all(data);
		free(instr);
		return (1);
	}
	//execute_instructions(data->instructions);
	return (0);
}
