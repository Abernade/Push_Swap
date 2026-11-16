# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/29 08:35:39 by arbernad          #+#    #+#              #
#    Updated: 2026/11/15 17:04:36 by arbernad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS := checker
OBJ_DIR := obj
BONUS_OBJ_DIR := bonus_obj
SRC_DIR := srcs
BONUS_SRC_DIR := bonus_srcs
LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

# PENSER A ENLEVER test_utils.c
SRC := push_swap.c \
		parser.c \
		math_utils.c \
		lst_utils.c \
		test_utils.c \
		disorder.c \
		error.c \
		op_push_swap.c \
		op_rotate.c \
		op_utils.c \
		op_optimize.c \
		rotation_list_utils.c \
		indexer.c \
		index_utils.c \
		init_utils.c \
		bucket_sort.c \
		bucket_init.c \
		bucket_sort_utils.c \
		bucket_sort_prevision.c \
		bucket_push_b.c \
		insertion_sort.c \
		print_bench.c \
		radix.c \
		turkish_sort.c \
		turkish_utils.c

BONUS_SRC := checker_bonus.c \
				init_utils.c \
				parser.c \
				error.c \
				op_utils.c \
				op_rotate.c \
				op_push_swap.c

BONUS_SRCS := $(BONUS_SRCS:%.c=$(BONUS_SRC_DIR)/%.c)
SRCS := $(SRC:%.c=$(SRC_DIR)/%.c)
BONUS_OBJ := $(BONUS_SRC:%.c=$(BONUS_OBJ_DIR)/%.o)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDE := -I.
VPATH := srcs bonus_srcs

all: $(NAME)

bonus: $(NAME_BONUS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: %.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS) : $(BONUS_OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJ) $(LIBFT) -o $(NAME_BONUS)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ)
	rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
