/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraf <achraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:02:32 by achraf            #+#    #+#             */
/*   Updated: 2024/03/23 03:35:12 by achraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	printf("unique philo simulation !\n");
	(void)arg;
	return (NULL);
}

void	*simulation(void *arg)
{
	printf("multi philos simulation !\n");
	(void)arg;
	return (NULL);
}

void	start_simulation(t_info *info)
{
	int i;

	i = -1;
	if (info->max_meal == 0)
		return ;
	else if (info->philo_num == 1)
		safe_thread(info->philos[0].thread_id, one_philo, &info->philos[0], 0);
	else
	{
		while (++i < info->philo_num)
			safe_thread(info->philos[i].thread_id, simulation, &info->philos[i], 0);
	}
}