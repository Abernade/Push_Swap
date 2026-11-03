# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arbernad <arbernad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/29 08:35:39 by arbernad          #+#    #+#              #
#    Updated: 2026/11/03 12:19:55 by arbernad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
OBJ_DIR := obj
SRC_DIR := srcs
LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

# PENSER A ENLEVER test_utils.c
SRC := push_swap.c \
		parser.c \
		test_utils.c \
		disorder.c \
		error.c \
		instr_push_swap.c \
		instr_rotate.c \
		instr_utils.c \
		indexer.c

SRCS := $(SRC:%.c=$(SRC_DIR)/%.c)
OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDE := -I.
VPATH := srcs

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(INCLUDE) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
