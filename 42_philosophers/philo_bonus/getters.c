/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:06:29 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/11 17:07:19 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_last_eat_time(t_data *data)
{
	long	time;

	sem_wait(data->philo.sem_philo);
	time = data->philo.last_eat_time;
	sem_post(data->philo.sem_philo);
	return (time);
}

t_state	get_philo_state(t_data *data)
{
	t_state	state;

	sem_wait(data->philo.sem_philo);
	state = data->philo.state;
	sem_post(data->philo.sem_philo);
	return (state);
}

long	get_start_time(t_data *data)
{
	return (data->start_time);
}
