# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 15:45:06 by alassiqu          #+#    #+#              #
#    Updated: 2024/01/27 16:15:49 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS	= checker
HEADER	= push_swap.h

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

SRCS	= operations/reverse_rotate_action.c operations/rotate_action.c operations/push_action.c operations/swap_action.c
SRCS	+= stack_utils_0.c stack_utils_1.c
SRCS	+= push_swap.c push_swap_utils_0.c
# SRCS	+= 
OBJS	= $(SRCS:.c=.o)

SRCS_B	= 
OBJS_B	= $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(BONUS)

clean:
	$(RM) $(OBJS)

clean_bonus:
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

fclean_bonus: clean_bonus
	$(RM) $(NAME)

re: fclean all

re_b: fclean_bonus bonus

.PHONY: all bonus clean clean_b fclean fclean_b re re_b