/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_gets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:27:39 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/27 00:57:46 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	safe_mutex(mutex, 1);
	*dest = value;
	safe_mutex(mutex, 2);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool ret;

	safe_mutex(mutex, 1);
	ret = *value;
	safe_mutex(mutex, 2);
	return (ret);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	safe_mutex(mutex, 1);
	*dest = value;
	safe_mutex(mutex, 2);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long ret;

	safe_mutex(mutex, 1);
	ret = *value;
	safe_mutex(mutex, 2);
	return (ret);
}

bool    simulation_finished(t_info *info)
{
    return (get_bool(&info->info_mutex, &info->end_simulation));
}
