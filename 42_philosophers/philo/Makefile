# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 23:27:50 by alassiqu          #+#    #+#              #
#    Updated: 2024/03/12 00:12:40 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= error_utils.c parsing.c utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) philo.c -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	clean all fclean
.SECONDARY:	$(OBJS)