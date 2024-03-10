/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:39:03 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/10 20:49:07 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_input(t_info *info, char **av)
{
	info->philo_num = ft_atol(av[1]);
	info->time_to_die = ft_atol(av[2]) * 1e3;
	info->time_to_eat = ft_atol(av[3]) * 1e3;
	info->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (av[5])
		info->max_meal = ft_atol(av[5]);
	else
		info->max_meal = -1;
	if (info->time_to_die < 6e3 || info->time_to_sleep < 6e3
		|| info->time_to_eat < 6e3)
		ft_error();
}

void	init_data(t_info *info)
{
	info->end_simulation = false;
	info->philos = malloc(sizeof(t_philo) * info->philo_num);
	if (!info->philos)
		ft_error();
}
