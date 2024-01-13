# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 18:03:03 by alassiqu          #+#    #+#              #
#    Updated: 2024/01/13 18:07:20 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

SRCS	= parsing/*.c needed_functions/*.c errors/errors.c 42_get-next-line/*.c
HEADER	= includes/so_long.h

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER)