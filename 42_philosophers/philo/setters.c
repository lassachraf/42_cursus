/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:16:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/13 21:16:14 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_keep_iterating(t_data *data, bool set_to)
{
	pthread_mutex_lock(&data->keep_iter_mutex);
	data->still_iter = set_to;
	pthread_mutex_unlock(&data->keep_iter_mutex);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->state_mutex);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->state_mutex);
}
