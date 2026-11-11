/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:32:21 by vldryga           #+#    #+#             */
/*   Updated: 2026/11/10 16:20:23 by arbernad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //à enlever !!!
# include "libft/libft.h"

/**
 *  Bucket sort related macros
 *
 * 	Flags to be used in `bucket_offset_forward`
 * 	and `bucket_offset_backward` functions
 * 	`ANY` is equivalent to `TOP | BOTTOM`
 */
# define TOP 1
# define BOTTOM 2
# define ANY 3

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
	int			a_size;
	int			b_size;
}	t_pushswap;

/**
 *	/!\ TO BE DELETED /!\
 * 	test_utils.c functions and bitflags
 */
#define PRINT_NB 1
#define PRINT_IDX 2
#define PRINT_BUCKET 4
#define PRINT_INSTRUCTIONS 8
#define PRINT_PREVISION_A 16
#define PRINT_PREVISION_B 32

void	print_stacks(t_pushswap *data, int bitflags);
void	print_config(t_config *config);
void	printf_stacks(t_pushswap *data);
void	print_instruction_list(t_pushswap *data);



// parser.c
t_list	*parser(char **av, t_config *flags);
double	disorder(t_list *list_a, unsigned int size);
void	del_list(void *content);

// error.c
t_bool	has_flag_error(t_config *config);
t_bool	has_duplicate(t_list *lst);
void	msg_error(void);

// op_push_swap.c
int		swap_a(t_pushswap *data);
int		swap_b(t_pushswap *data);
int		push_a(t_pushswap *data);
int		push_b(t_pushswap *data);

// op_rotate.c
int		rotate_a(t_pushswap *data);
int		rotate_b(t_pushswap *data);
int		reverse_rotate_a(t_pushswap *data);
int		reverse_rotate_b(t_pushswap *data);

// op_utils.c
int		add_instr(t_pushswap *data, int instr);
void	multi_rotations(t_pushswap *data, int rotations);
void	reverse_multi_rotations(t_pushswap *data, int rotations);

// lst_utils.c
t_list	*lstnnext(t_list *node, int offset);
t_list	*lstnprev(t_list *node, int offset);

// math_utils.c
int		ft_abs(int n);
int		ft_sqrt(int n);
int		max(int a, int b);

// algo_simple.c
t_list	*simple_a(t_pushswap *data, int size);

//print_bench.c
void	print_bench(t_pushswap *data);


	/**
	*	BUCKET SORT
	*/

// bucket_sort.c
void	bucket_sort(t_pushswap *data);

// bucket_push_b.c
void	push_into_buckets(t_pushswap *data);

// bucket_init.c
void	bucket_init(t_pushswap *data);

// bucket_sort_utils.c
void	push_to_bucket(t_pushswap *data, int bucket, int position);
int		bucket_offset_forward(t_list *stack, int bucket, int position);
int		bucket_offset_backward(t_list *stack, int bucket, int position);

// bucket_sort_prevision.c
t_ops	get_prevision(t_pushswap *data, int bucket, int starting_pos);

// indexer.c
void	indexer(t_list *stack);

#endif
