/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:50:25 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/14 11:59:14 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_death(void *data_p)
{
	t_data	*data;

	data = (t_data *)data_p;
	while (should_stop(get_philo_state(data)) == false)
	{
		if (someone_died())
			return (set_philo_state(data, FINISH), NULL);
		if (philo_died(data))
		{
			sem_wait(data->sem_print);
			if (philo_died(data) && someone_died() == false)
			{
				set_philo_state(data, DEAD);
				let_others_know();
				printf("%lu %d %s\n", get_time() - get_start_time(data),
					data->philo.id, DIED);
				sem_post(data->sem_print);
				break ;
			}
			sem_post(data->sem_print);
		}
		usleep(1000);
	}
	return (NULL);
}

int	routine(t_data *data, int id)
{
	if (set_philo(data, id))
		exit(1);
	if (data->philo.id % 2 == 0)
		ft_usleep(data->eat_time - 10);
	if (pthread_create(&data->monitor, NULL, &monitor_death, data))
		return (-1);
	while (true)
	{
		if (dine(data) || should_stop(get_philo_state(data)))
			break ;
		if (rest(data) || should_stop(get_philo_state(data)))
			break ;
		if (ponder(data))
			break ;
	}
	if (pthread_join(data->monitor, NULL))
		exit(1);
	sem_close(data->philo.sem_philo);
	exit(0);
}
