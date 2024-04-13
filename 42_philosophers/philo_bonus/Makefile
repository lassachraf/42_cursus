# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 07:09:02 by alassiqu          #+#    #+#              #
#    Updated: 2024/04/12 08:58:37 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread #-g -fsanitize=address
RM		= rm -rf

SRCS	= actions.c death_utils.c getters.c init.c meal_utils.c parsing.c
SRCS	+= routine.c setters.c simulation.c time.c utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) philo_bonus.c -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

bouns: all

re: fclean all

.PHONY: all clean fclean re