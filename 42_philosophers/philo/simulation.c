/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:02:32 by achraf            #+#    #+#             */
/*   Updated: 2024/03/27 00:55:58 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	return (NULL);
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->info);
	return (NULL);
}

void	start_simulation(t_info *info)
{
	int	i;

	i = -1;
	if (info->max_meal == 0)
		return ;
	else if (info->philo_num == 1)
		safe_thread(&info->philos[0].thread_id, &one_philo, &info->philos[0], 0);
	else
	{
		while (++i < info->philo_num)
			safe_thread(&info->philos[i].thread_id, &simulation, &info->philos[i],
				0);
	}
	set_bool(&info->info_mutex, &info->ready, true);
}
