# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 15:11:03 by alassiqu          #+#    #+#              #
#    Updated: 2024/02/07 19:53:52 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
BONUS	= so_long_b
CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

HEADER	= includes/so_long.h
SRCS_B	= parsing/check_extension.c parsing/check_map_0.c parsing/check_map_1.c parsing/floodfill_parsing.c
SRCS_B	+= errors/ft_errors.c errors/ft_map_error.c errors/ft_exit.c
SRCS_B	+= utils/ft_strncmp.c utils/ft_split.c utils/ft_strlcpy.c utils/ft_strchr.c utils/ft_strlen.c utils/ft_strjoin.c utils/ft_itoa.c
SRCS_B	+= 42_get-next-line/get_next_line.c 42_get-next-line/get_next_line_utils.c 
SRCS_B	+= so_long_utils_0.c so_long_utils_1.c so_long_utils_2.c
SRCS_B	+= animation/animation.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) so_long.c -I $(HEADER) -o $(NAME)

bonus: $(OBJS_B)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS_B) so_long.c -I $(HEADER) -o $(BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_B)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(OBJS_B)