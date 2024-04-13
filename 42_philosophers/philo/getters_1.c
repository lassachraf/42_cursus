/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 05:45:41 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/09 05:47:44 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_die_time(t_data *data)
{
	long	die_time;

	pthread_mutex_lock(&data->die_mutex);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->die_mutex);
	return (die_time);
}

long	get_sleep_time(t_data *data)
{
	long	sleep_time;

	pthread_mutex_lock(&data->sleep_mutex);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->sleep_mutex);
	return (sleep_time);
}

long	get_eat_time(t_data *data)
{
	long	eat_time;

	pthread_mutex_lock(&data->eat_mutex);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->eat_mutex);
	return (eat_time);
}

long	get_last_meal_time(t_philo *philo)
{
	long	last_eat_time;

	pthread_mutex_lock(&philo->last_meal_time_mutex);
	last_eat_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	return (last_eat_time);
}
