/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:16:02 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/14 12:01:10 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	START = 5
}					t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	meals_had_mutex;
	pthread_mutex_t	last_meal_time_mutex;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				max_meals;
	bool			still_iter;
	long			eat_time;
	long			die_time;
	long			sleep_time;
	long			start_time;
	pthread_t		*thread;
	pthread_t		all_alive;
	pthread_t		all_full;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	nb_philos_mutex;
	pthread_mutex_t	keep_iter_mutex;
	pthread_mutex_t	start_time_mutex;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

// parsing.c
long				ft_atol(char *s);
int					ft_check_input(int ac, char **av);
void				arg_error(void);
void				print_state(t_data *data, int id, char *msg);

// init.c
int					init_forks(t_data *data);
int					init_philos(t_data *data);
int					allocate(t_data *data);
int					init_data(t_data *data, char **av);

// simulation.c
int					lessgo(t_data *data);
int					simulation(char **av);

// routine.c
bool				is_philo_full(t_data *data, t_philo *philo);
void				notify_all_philos(t_data *data);
void				*routine(void *data);
void				*all_alive(void *info);
void				*all_full(void *info);

// time.c
void				ft_usleep(long time);
long				get_time(void);

// meal_utils.c
int					take_forks(t_philo *philo);
void				drop_forks(t_philo *philo);
void				update_last_meal_time(t_philo *philo);
void				update_nb_meals_had(t_philo *philo);
bool				philo_died(t_philo *philo);

// actions.c
int					dine(t_philo *philo);
int					rest(t_philo *philo);
int					ponder(t_philo *philo);

// meal_utils_1.c
int					one_philo(t_philo *philo);
int					take_left_fork(t_philo *philo);
int					take_right_fork(t_philo *philo);
void				drop_left_fork(t_philo *philo);
void				drop_right_fork(t_philo *philo);

// getters.c
int					get_nb_philos(t_data *data);
t_state				get_philo_state(t_philo *philo);
int					get_nb_meals_philo_had(t_philo *philo);
long				get_start_time(t_data *data);
bool				get_keep_iter(t_data *data);

// getters_1.c
long				get_die_time(t_data *data);
long				get_sleep_time(t_data *data);
long				get_eat_time(t_data *data);
long				get_last_meal_time(t_philo *philo);

// setters.c
void				set_keep_iterating(t_data *data, bool set_to);
void				set_philo_state(t_philo *philo, t_state state);

#endif