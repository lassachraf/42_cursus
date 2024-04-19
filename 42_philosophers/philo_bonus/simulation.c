/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 03:37:37 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/16 14:43:42 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	processes(t_data *data)
{
	pid_t	pid;
	int		i;

	i = 0;
	data->start_time = get_time();
	while (i++ < data->nb_philos)
	{
		pid = fork();
		if (pid == 0)
			routine(data, i);
		else if (pid == -1)
			return (-1);
	}
	pid = waitpid(0, NULL, 0);
	while (pid != -1)
		pid = waitpid(0, NULL, 0);
	return (0);
}

int	clean_up(t_data *data)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_print);
	return (0);
}

int	simulation(char **av)
{
	t_data	data;

	if (init_data(&data, av) != 0)
		return (-1);
	processes(&data);
	clean_up(&data);
	return (0);
}
