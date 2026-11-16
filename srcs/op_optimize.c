/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:43:50 by arbernad          #+#    #+#             */
/*   Updated: 2026/11/15 16:55:43 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_rotation(t_ops *rotations, char *str)
{
	if (!ft_strcmp(str, "ra"))
		rotations->rt_a++;
	else if (!ft_strcmp(str, "rb"))
		rotations->rt_b++;
	else if (!ft_strcmp(str, "rra"))
		rotations->revrt_a++;
	else if (!ft_strcmp(str, "rrb"))
		rotations->revrt_b++;
	else if (!ft_strcmp(str, "rr"))
		rotations->rt_ab++;
	else if (!ft_strcmp(str, "rrr"))
		rotations->revrt_ab++;
}

static t_list	*new_rot_sequence(t_ops *rot)
{
	t_list	*new;

	new = NULL;
	while (rot->rt_a && rot->rt_b)
	{
		rot->rt_a--;
		rot->rt_b--;
		rot->rt_ab++;
	}
	while (rot->revrt_a && rot->revrt_b)
	{
		rot->revrt_a--;
		rot->revrt_b--;
		rot->revrt_ab++;
	}
	new = create_rotation_list(rot);
	return (new);
}

static void	lst_replace(t_list *new, t_list *start, t_list *end)
{
	t_list	*last_new;

	last_new = ft_lstlast(new);
	if (start->prev)
		start->prev->next = new;
	if (end->next)
		end->next->prev = last_new;
	new->prev = start->prev;
	last_new->next = end->next;
	end->next = NULL;
	ft_lstclear(&start, &del_list);
}

static t_list	*optimize(t_list **op_lst, t_list *start, t_ops *rot)
{
	t_list	*new_sequence;
	t_list	*end;

	new_sequence = new_rot_sequence(rot);
	if (!new_sequence)
		return (NULL);
	end = start;
	while (end->next && is_rotation_str(end->next->content))
		end = end->next;
	lst_replace(new_sequence, start, end);
	if (!new_sequence->prev)
		*op_lst = new_sequence;
	while (new_sequence && is_rotation_str(new_sequence->content))
		new_sequence = new_sequence->next;
	return (*op_lst);
}

int	optimize_rotations(t_list **op_lst)
{
	t_list	*node;
	t_list	*next;
	t_list	*start;
	t_ops	instructions;
	t_bool	in_rotation;

	ft_bzero(&instructions, sizeof(t_ops));
	in_rotation = FALSE;
	node = *op_lst;
	while (node)
	{
		next = NULL;
		if (is_rotation_str(node->content))
		{
			if (!in_rotation)
				start = node;
			in_rotation = TRUE;
			add_rotation(&instructions, node->content);
		}
		else if (in_rotation)
		{
			in_rotation = FALSE;
			next = node->next;
			if ((instructions.rt_a && instructions.rt_b)
				|| (instructions.revrt_a && instructions.revrt_b))
				*op_lst = optimize(op_lst, start, &instructions);
			ft_bzero(&instructions, sizeof(t_ops));
		}
		if (!*op_lst)
			return (1);
		if (next)
			node = next;
		else
			node = node->next;
	}
	return (0);
}
