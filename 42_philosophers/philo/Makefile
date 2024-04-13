NAME	= philo

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread #-g -fsanitize=address
RM		= rm -rf

HEADER	= include/philo.h

SRCS	= actions.c getters_1.c getters.c init.c meal_utils_1.c meal_utils.c
SRCS	+= parsing.c routine.c setters.c simulation.c time.c
# SRCS	+= getters.c getters_1.c setters.c
#routine.c time.c utils.c monitor.c eat_1.c eat_2.c sleep.c think.c getters_1.c getters_2.c setters.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) philo.c -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re