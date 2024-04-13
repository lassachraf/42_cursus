/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 03:38:23 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/10 05:48:07 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_semaphores(t_data *data)
{
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/print");
	data->sem_forks = sem_open("/forks", O_CREAT, 0644, data->nb_philos);
	data->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	if (!data->sem_forks || !data->sem_print)
		return (-1);
	sem_unlink("/forks");
	sem_unlink("/print");
	return (0);
}

int init_data(t_data *data, char **av)
{
    data->nb_philos = ft_atol(av[1]);
	data->die_time = ft_atol(av[2]);
	data->eat_time = ft_atol(av[3]);
	data->sleep_time = ft_atol(av[4]);
	data->max_meals = ft_atol(av[5]);
    data->philo.data = data;
	data->philo.meals_had = 0;
	data->philo.state = START;
    return (init_semaphores(data));
}
