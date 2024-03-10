/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:16:17 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/10 20:50:58 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_info	t_info;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				meal_counter;
	int				full;
	int				meal_time;
	t_fork			*right_fork;
	t_fork			*left_fork;
	pthread_t		*thread_id;
	t_info			*info;
}					t_philo;

typedef struct s_info
{
	long		philo_num;
	long		time_to_eat;
	long		time_to_die;
	long		time_to_sleep;
	long		max_meal;
	bool		start_simulation;
	bool		end_simulation;
	t_fork		*forks;
	t_philo		*philos;
}				t_info;

// Errors functions :
void	ft_error(void);

// Parsing functions :
long	ft_atol(char *str);
void	parsing_input(t_info *info, char **av);

// Initializing data :
void	init_data(t_info *info);

#endif