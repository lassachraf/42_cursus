/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:23:14 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/12 08:37:21 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	someone_died(void)
{
	sem_t	*death;

	death = sem_open("/death", AT_EACCESS, 0);
	if (death == SEM_FAILED)
		return (false);
	sem_close(death);
	return (true);
}

void	let_others_know(void)
{
	sem_open("/death", O_CREAT, 0644, 0);
}

bool	philo_died(t_data *data)
{
	if (get_philo_state(data) != EATING
		&& get_time() - get_last_eat_time(data) > data->die_time)
		return (true);
	return (false);
}
