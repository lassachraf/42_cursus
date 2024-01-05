# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 09:16:33 by alassiqu          #+#    #+#              #
#    Updated: 2024/01/05 22:47:42 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME	= pipex
# NAME_B	= pipex_bonus
# HEADER	= pipex.h

# CC		= cc
# CFLAGS	= -Wall -Wextra -Werror

# RM		= rm -f

# SRCS	= pipex.c pipex_utils.c
# BONUS	= pipex_bonus.c pipex_bonus_utils.c

# OBJS	= $(SRCS:.c=.o)
# OBJS_B	= $(BONUS:.c=.o)

# $(NAME): $(SRCS) $(OBJS) $(HEADER)
# 	@make re -C 42_libft/
# 	@$(CC) $(CFLAGS) $(OBJS) -L42_libft -lft -o $(NAME)

# all: $(NAME)

# bonus: $(BONUS) $(OBJS_B) $(HEADER)
# 	@make re -C 42_libft/
# 	@$(CC) $(CFLAGS) $(OBJS) -L42_libft -lft -o $(NAME_B)

# clean:
# 	@make clean -C 42_libft/
# 	@$(RM) $(OBJS) $(OBJS_B)

# fclean: clean
# 	@make fclean -C 42_libft/
# 	@$(RM) $(NAME) $(BONUS)

# re: fclean all

# .PHONY: clean all fclean re bonus

NAME	= pipex
HEADER	= pipex.h

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

SRCS	= pipex.c pipex_utils.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(SRCS) $(OBJS) $(HEADER)
	@make re -C 42_libft/
	@$(CC) $(CFLAGS) $(OBJS) -L42_libft -lft -o $(NAME)

all: $(NAME)

clean:
	@make clean -C 42_libft/
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C 42_libft/
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re
