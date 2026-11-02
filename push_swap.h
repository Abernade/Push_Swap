/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:32:21 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/02 16:18:12 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //à enlever !!!
# include "libft/libft.h"

enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef enum
{
	FALSE = 0,
	TRUE
}	t_bool;


typedef struct s_config
{
	t_bool	flag_simple;
	t_bool	flag_medium;
	t_bool	flag_complex;
	t_bool	flag_adaptative;
	t_bool	flag_bench;
	float	disorder;
}	t_config;

typedef struct s_pushswap
{
	t_config	*config;
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*instructions;
}	t_pushswap;

// test_utils.c
void	print_stack(t_list *stack);
void	print_config(t_config *config);

// parser.c
t_list	*parser(char **av, t_config *flags);
double	disorder(t_list *list_a, unsigned int size);

// error.c
t_bool	has_flag_error(t_config *config);
t_bool	has_duplicate(t_list *lst);
void	msg_error(void);

// instr_push_swap.c
void	swap_b(t_pushswap *data);
void	push_a(t_pushswap *data);
void	push_b(t_pushswap *data);
void	swap_a(t_pushswap *data);

// instr_rotate.c
int		rotate_a(t_pushswap *data);
int		rotate_b(t_pushswap *data);
int		reverse_rotate_a(t_pushswap *data);
int		reverse_rotate_b(t_pushswap *data);

// instr_utils.c
int		add_instr(t_pushswap *data, int instr);

#endif
