/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:04:57 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/11 17:10:12 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*create_sem_name(int id)
{
	return (ft_strjoin("/philo_", ft_itoa(id)));
}

int	set_philo(t_data *data, int id)
{
	char	*sem_name;

	sem_name = create_sem_name(id);
	if (sem_name == NULL)
		exit(1);
	sem_unlink(sem_name);
	data->philo.sem_philo = sem_open(sem_name, O_CREAT, 0644, 1);
	sem_unlink(sem_name);
	free(sem_name);
	data->philo.id = id;
	update_last_meal_time(data);
	return (0);
}

void	set_philo_state(t_data *data, t_state state)
{
	sem_wait(data->philo.sem_philo);
	data->philo.state = state;
	sem_post(data->philo.sem_philo);
}

void	update_last_meal_time(t_data *data)
{
	sem_wait(data->philo.sem_philo);
	data->philo.last_eat_time = get_time();
	sem_post(data->philo.sem_philo);
}
