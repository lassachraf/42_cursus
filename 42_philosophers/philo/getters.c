/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:15:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/13 21:26:21 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->state_mutex);
	state = philo->state;
	pthread_mutex_unlock(&philo->state_mutex);
	return (state);
}

int	get_nb_philos(t_data *data)
{
	int	nb_philos;

	pthread_mutex_lock(&data->nb_philos_mutex);
	nb_philos = data->nb_philos;
	pthread_mutex_unlock(&data->nb_philos_mutex);
	return (nb_philos);
}

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->meals_had_mutex);
	nb_meals_had = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meals_had_mutex);
	return (nb_meals_had);
}

long	get_start_time(t_data *data)
{
	long	time;

	pthread_mutex_lock(&data->start_time_mutex);
	time = data->start_time;
	pthread_mutex_unlock(&data->start_time_mutex);
	return (time);
}

bool	get_keep_iter(t_data *data)
{
	bool	ref;

	pthread_mutex_lock(&data->keep_iter_mutex);
	ref = data->still_iter;
	pthread_mutex_unlock(&data->keep_iter_mutex);
	return (ref);
}
