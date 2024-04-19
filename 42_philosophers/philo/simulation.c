/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:16:20 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/16 11:55:28 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lessgo(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_nb_philos(data);
	i = -1;
	data->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->thread[i], NULL, &routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->all_alive, NULL, &all_alive, data))
		return (1);
	if (data->max_meals > 0 && pthread_create(&data->all_full, NULL, &all_full,
			data))
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	if (pthread_join(data->all_alive, NULL))
		return (1);
	if (data->max_meals > 0 && pthread_join(data->all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->thread[i], NULL))
			return (1);
	}
	return (0);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].state_mutex);
		pthread_mutex_destroy(&data->philos[i].meals_had_mutex);
		pthread_mutex_destroy(&data->philos[i].last_meal_time_mutex);
	}
	pthread_mutex_destroy(&data->die_mutex);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->sleep_mutex);
	pthread_mutex_destroy(&data->nb_philos_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->keep_iter_mutex);
	pthread_mutex_destroy(&data->start_time_mutex);
	free(data->thread);
	free(data->philos);
	free(data->forks);
}

int	simulation(char **av)
{
	t_data	data;

	if (init_data(&data, av) == -1)
		return (-1);
	init_philos(&data);
	init_forks(&data);
	lessgo(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}
