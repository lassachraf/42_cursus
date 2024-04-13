/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 05:30:39 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/09 06:57:22 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (get_nb_philos(philo->data) == 1)
		return (one_philo(philo));
	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		drop_right_fork(philo);
		return (1);
	}
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
}

void	update_nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_had_mutex);
	philo->meal_counter++;
	pthread_mutex_unlock(&philo->meals_had_mutex);
}

bool	philo_died(t_philo *philo)
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if (get_time() - get_last_meal_time(philo) > get_die_time(data)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}
