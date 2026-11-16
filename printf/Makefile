# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vldryga <vldryga@student.42angouleme.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/23 11:23:32 by vldryga           #+#    #+#              #
#    Updated: 2026/11/04 09:42:03 by vldryga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra -I. -g
NAME := libftprintf.a
SRCS := ft_printf.c \
		formating_chars.c \
		formating_nb.c \
		formating_hexa.c
OBJS := $(SRCS:.c=.o)
LIBFT := ./libft/libft.a
INCLUDES := libft/libft.h ft_printf.h

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
