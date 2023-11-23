# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 17:51:02 by alassiqu          #+#    #+#              #
#    Updated: 2023/11/23 18:53:11 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIB		= ar -rc
RM		= rm -f

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_print_unsigned.c
SRC += ft_print_hexa_up.c ft_print_hexa_low.c ft_print_address.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re