# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 14:30:57 by alassiqu          #+#    #+#              #
#    Updated: 2024/01/11 18:36:30 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
NAME_B		=	pipex_bonus
HEADER		=	includes/pipex_mand.h
HEADER_B	=	includes/pipex_bonus.h

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
LIB			=	./42_libft/42_libft.a

SRCS 		=	srcs/mandatory/pipex_mand.c srcs/mandatory/execute.c srcs/mandatory/get_fullcmd.c \
				srcs/mandatory/dbl_free.c srcs/mandatory/error.c srcs/mandatory/safe_open.c \
				srcs/mandatory/safe_dup2.c srcs/mandatory/get_path.c

BONUS		=	srcs/bonus/pipex_bonus.c srcs/bonus/execute.c \
				srcs/bonus/get_fullcmd.c srcs/bonus/get_next_line.c \
				srcs/bonus/get_path.c srcs/bonus/safe_open.c srcs/bonus/error.c \
				srcs/bonus/safe_dup2.c srcs/bonus/dbl_free.c

OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(BONUS:.c=.o)

LIB			= 42_libft/libft.a

all: $(NAME)
bonus: $(NAME_B)

$(LIB):
	@make -C 42_libft/ --quiet

$(NAME): $(OBJS) $(HEADER) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) -I $(HEADER) -L42_libft -lft -o $(NAME)

$(NAME_B):$(OBJS_B) $(HEADER_B) $(LIB)
	$(CC) $(CFLAGS) $(OBJS_B) -I $(HEADER_B) -L42_libft -lft -o $(NAME_B)

clean:
	@$(RM) $(OBJS)
	@make clean -C 42_libft --quiet

clean_bonus:
	@$(RM) $(OBJS_B)
	@make clean -C 42_libft --quiet

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C 42_libft --quiet

fclean_bonus: clean_bonus
	@$(RM) $(NAME_B)
	@make fclean -C 42_libft --quiet

re: fclean all
re_bonus: fclean_b bonus

.PHONY: all clean clean_bonus fclean fclean_bonus bonus re re_bonus 