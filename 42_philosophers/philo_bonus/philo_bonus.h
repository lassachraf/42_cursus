/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 07:12:18 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/12 08:57:15 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_state
{
	EATING,
	DEAD,
	SLEEPING,
	FULL,
	START,
	FINISH
}					t_state;

struct s_data;

typedef struct s_philo
{
	int				id;
	int				meals_had;
	struct s_data	*data;
	t_state			state;
	long			last_eat_time;
	sem_t			*sem_philo;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				max_meals;
	long			eat_time;
	long			die_time;
	long			sleep_time;
	long			start_time;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	pthread_t		monitor;
	t_philo			philo;
}					t_data;

// parsing.c
long				ft_atol(char *s);
int					ft_check_input(int ac, char **av);
void				arg_error(int flag);
int					print_state(t_data *data, char *msg);

// utils.c
size_t				ft_strlen(char *s);
char				*ft_itoa(int n);
char				*ft_strjoin(char *s1, char *s2);
bool				should_stop(t_state state);

// init.c
int					init_semaphores(t_data *data);
int					init_data(t_data *data, char **av);

// meal_utils.c
int					take_forks(t_data *data);
int					drop_forks(t_data *data);
bool				nb_meals_option_given(t_data *data);
bool				philo_is_full(t_data *data);

// getters.c
long				get_last_eat_time(t_data *data);
t_state				get_philo_state(t_data *data);
long				get_start_time(t_data *data);

// setters.c
int					set_philo(t_data *data, int id);
void				set_philo_state(t_data *data, t_state state);
void				update_last_meal_time(t_data *data);

// actions.c
int					dine(t_data *data);
int					rest(t_data *data);
int					ponder(t_data *data);

// simulation.c
int					processes(t_data *data);
int					simulation(char **av);

// routine.c
int					routine(t_data *data, int id);

// time.c
void				ft_usleep(long sleep_time);
long				get_time(void);

// death_utils.c
bool				someone_died(void);
void				let_others_know(void);
bool				philo_died(t_data *data);

#endif