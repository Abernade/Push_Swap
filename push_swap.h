/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:32:21 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/02 10:37:32 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //à enlever !!!
# include "libft/libft.h"

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
t_list	*parser(char **av, int argc, t_config *flags);
double	disorder(t_list *list_a, unsigned int size);

// error.c
t_bool	has_flag_error(t_config *config);
t_bool	has_duplicate(t_list *lst);
void	msg_error(void);

#endif
