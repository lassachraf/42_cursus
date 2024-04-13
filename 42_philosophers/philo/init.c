/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:14:34 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/09 06:11:42 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = data->philos;
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].left_f = &data->forks[0];
	philos[0].right_f = &data->forks[data->nb_philos - 1];
	while (++i < data->nb_philos)
	{
		philos[i].left_f = &data->forks[i];
		philos[i].right_f = &data->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	while (++i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].meal_counter = 0;
		philos[i].state = START;
		pthread_mutex_init(&philos[i].state_mutex, NULL);
		pthread_mutex_init(&philos[i].meals_had_mutex, NULL);
		pthread_mutex_init(&philos[i].last_meal_time_mutex, NULL);
		update_last_meal_time(&philos[i]);
	}
	return (0);
}

int	allocate(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philos)
		return (-1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (free(data->philos), -1);
	data->thread = malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->thread)
		return (free(data->philos), free(data->forks), -1);
	return (0);
}

int	init_data(t_data *data, char **av)
{
	data->nb_philos = ft_atol(av[1]);
	data->die_time = ft_atol(av[2]);
	data->eat_time = ft_atol(av[3]);
	data->sleep_time = ft_atol(av[4]);
	data->max_meals = ft_atol(av[5]);
	data->meals_eaten = 0;
	data->full_philo = 0;
	data->still_iter = true;
	pthread_mutex_init(&data->die_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->sleep_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->nb_philos_mutex, NULL);
	pthread_mutex_init(&data->keep_iter_mutex, NULL);
	pthread_mutex_init(&data->start_time_mutex, NULL);
	return (allocate(data));
}
