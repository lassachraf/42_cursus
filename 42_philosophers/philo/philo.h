/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraf <achraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:16:17 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/18 02:34:34 by achraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// pthread create return :
# define EPERM 1
# define EINVAL 22
# define EDEADLK 35
# define ENOMEM 12
# define EBUSY 16

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_info	t_info;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	long				id;
	long				meal_counter;
	bool				full;
	long				meal_time;
	t_fork				*fork_1;
	t_fork				*fork_2;
	pthread_t			*thread_id;
	pthread_mutex_t		philo_mutex;
	t_info				*info;
}						t_philo;

typedef struct s_info
{
	long				philo_num;
	long				time_to_eat;
	long				time_to_die;
	long				time_to_sleep;
	long				max_meal;
	bool				start_simulation;
	bool				end_simulation;
	t_fork				*forks;
	t_philo				*philos;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		info_mutex;
}						t_info;

// Errors functions :
void					ft_error(char *s);
void					ft_args_error(void);
void					free_and_cleanup(t_info *info);

// Parsing functions :
long					ft_atol(char *str);
void					parsing_input(t_info *info, char **av);
int						ft_strlen(char *s);

// Safe functions :
void					*safe_malloc(size_t bytes);
void					safe_mutex(pthread_mutex_t *mutex, int flag);
void					safe_thread(pthread_t *thread, void *(*func)(void *),
							void *arg, int flag);

// Initializing data :
void					init_data(t_info *info);

// Simulation :
void					start_simulation(t_info *info);


#endif