/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:39:44 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/14 11:28:05 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	take_forks(t_data *data)
{
	sem_wait(data->sem_forks);
	if (print_state(data, TAKE_FORKS))
	{
		sem_post(data->sem_forks);
		return (1);
	}
	if (data->nb_philos == 1)
		return (1);
	sem_wait(data->sem_forks);
	if (should_stop(get_philo_state(data)))
	{
		drop_forks(data);
		return (1);
	}
	if (print_state(data, TAKE_FORKS))
	{
		drop_forks(data);
		return (1);
	}
	return (0);
}

int	drop_forks(t_data *data)
{
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
	return (0);
}

bool	philo_is_full(t_data *data)
{
	if (data->max_meals <= 0)
		return (false);
	if (data->max_meals <= data->philo.meals_had)
	{
		set_philo_state(data, FULL);
		return (true);
	}
	return (false);
}
