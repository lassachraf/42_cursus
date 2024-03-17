/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraf <achraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:43:22 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/17 00:05:01 by achraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (-1);
	while (str[i] && (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ft_error("Feed me positive number !\n");
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX)
		ft_error("You depassed the INT_MAX !\n");
	return (res *= sign);
}

void	free_and_cleanup(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < info->philo_num)
	{
		philo = info->philos + i;
		safe_mutex(&philo->philo_mutex, 3);
	}
	safe_mutex(&info->write_mutex, 3);
	safe_mutex(&info->info_mutex, 3);
	free(info->forks);
	free(info->philos);
}