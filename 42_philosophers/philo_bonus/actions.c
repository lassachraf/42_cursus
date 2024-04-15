/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:13:12 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/15 20:18:54 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	dine(t_data *data)
{
	if (take_forks(data))
		return (1);
	update_last_meal_time(data);
	set_philo_state(data, EATING);
	if (print_state(data, EAT))
	{
		drop_forks(data);
		return (1);
	}
	ft_usleep(data->eat_time);
	drop_forks(data);
	data->philo.meals_had++;
	if (philo_is_full(data))
		return (1);
	return (0);
}

int	rest(t_data *data)
{
	set_philo_state(data, SLEEPING);
	if (print_state(data, SLEEP))
		return (1);
	ft_usleep(data->sleep_time);
	return (0);
}

int	ponder(t_data *data)
{
	if (print_state(data, THINK))
		return (1);
	return (0);
}
