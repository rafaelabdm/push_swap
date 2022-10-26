# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 18:10:00 by rabustam          #+#    #+#              #
#    Updated: 2022/10/17 13:46:31 by rabustam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

FLAGS	= -Wall -Werror -Wextra -g
CC		= cc $(FLAGS)

LIBFT	= libft/libft.a

SRCS	=	push_swap.c \
			check_error.c \
			swap_funcs.c \
			push_funcs.c \
			rotate_funcs.c \
			reverse_rotate_funcs.c \
			init_stacks.c \
			push_a_to_b.c \
			set_cost.c \
			push_back_v2.c

OBJS	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $^

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)


$(LIBFT):
	cd libft && $(MAKE)

clean:
	rm -f $(OBJS)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
