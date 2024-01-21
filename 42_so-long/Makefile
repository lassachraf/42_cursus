# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 15:11:03 by alassiqu          #+#    #+#              #
#    Updated: 2024/01/21 12:30:41 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

SRCS	= parsing/check_extension.c parsing/check_map_0.c parsing/check_map_1.c
SRCS	+= errors/ft_errors.c errors/ft_map_error.c errors/ft_exit.c
SRCS	+= utils/ft_strncmp.c utils/ft_split.c utils/ft_strlcpy.c utils/ft_strchr.c utils/ft_strlen.c utils/ft_strjoin.c utils/ft_itoa.c
SRCS	+= 42_get-next-line/get_next_line.c 42_get-next-line/get_next_line_utils.c 
SRCS	+= so_long_utils.c
HEADER	= includes/so_long.h

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) so_long.c -I $(HEADER) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re