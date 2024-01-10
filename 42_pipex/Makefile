# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 09:16:33 by alassiqu          #+#    #+#              #
#    Updated: 2024/01/10 17:04:04 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
NAME_B	= pipex_bonus
HEADER	= pipex.h

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

RM		= rm -f

SRCS	= pipex.c pipex_utils.c pipex_bonus_utils.c
BONUS	= pipex_bonus.c pipex_bonus_utils.c pipex_utils.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(BONUS:.c=.o)

$(NAME): $(OBJS) $(HEADER)
	@make -C 42_libft/ --quiet
	@$(CC) $(CFLAGS) $(OBJS) -L42_libft -lft -o $(NAME)

all: $(NAME)

bonus: $(OBJS_B)
	@make -C 42_libft/ --quiet
	@$(CC) $(CFLAGS) $(OBJS_B) -L42_libft -lft -o $(NAME_B)

clean:
	@make clean -C 42_libft/ --quiet
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@make fclean -C 42_libft/ --quiet
	@$(RM) $(NAME) $(NAME_B)

re: fclean all

bonus_re: fclean bonus

.PHONY: clean all fclean re bonus bonus_re
