/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:39:03 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/26 23:20:04 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_input(t_info *info, char **av)
{
	info->philo_num = ft_atol(av[1]);
	info->time_to_die = ft_atol(av[2]) * 1e3;
	info->time_to_eat = ft_atol(av[3]) * 1e3;
	info->time_to_sleep = ft_atol(av[4]) * 1e3;
	info->max_meal = ft_atol(av[5]);
	if (info->time_to_die < 6e4 || info->time_to_sleep < 6e4
		|| info->time_to_eat < 6e4)
		ft_error("Timestamp must be more than 60ms !\n");
}

void	assign_fork(t_philo *philo, t_fork *forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philo->info->philo_num;
	if (philo->id % 2 == 0)
	{
		philo->fork_1 = &forks[pos];
		philo->fork_2 = &forks[(pos + 1) % philo_nbr];
	}
	else
	{
		philo->fork_1 = &forks[(pos + 1) % philo_nbr];
		philo->fork_2 = &forks[pos];
	}
}

void	init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < info->philo_num)
	{
		philo = info->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meal_counter = 0;
		safe_mutex(&philo->philo_mutex, 0);
		philo->info = info;
		assign_fork(philo, info->forks, i);
	}
}

void	init_data(t_info *info)
{
	int	i;

	i = -1;
	info->end_simulation = false;
	info->ready = false;
	info->philos = safe_malloc(info->philo_num * sizeof(t_philo));
	info->forks = safe_malloc(info->philo_num * sizeof(t_fork));
	safe_mutex(&info->write_mutex, 0);
	safe_mutex(&info->info_mutex, 0);
	while (++i < info->philo_num)
	{
		safe_mutex(&info->forks[i].fork, 0);
		info->forks[i].fork_id = i;
	}
	init_philo(info);
}
