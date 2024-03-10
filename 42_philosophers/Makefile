# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 23:27:50 by alassiqu          #+#    #+#              #
#    Updated: 2024/03/09 23:33:22 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
BONUS	=

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= 
SRCS_B	=

OBJS	= $(SRCS:.o=.c)
OBJS_B	= $(SRCS_B:.o=.c)

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS)

bonus: $(BONUS)

$(BONUS):	$(OBJS_B)
	$(CC) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

.PHONY:	clean all fclean bonus
.SECONDARY:	$(OBJS) $(OBJS_B)