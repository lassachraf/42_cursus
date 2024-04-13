/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:19:17 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/12 08:56:36 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atol(char *s)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i] && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			return (-1);
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		result = result * 10 + (s[i++] - '0');
	if (!(s[i] < '0' && s[i] > '9') && s[i])
		return (-1);
	return (result);
}

int	ft_check_input(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		arg_error(1);
		return (-1);
	}
	if (ft_atol(av[1]) <= 0 || (ac == 6 && ft_atol(av[5]) <= 0))
	{
		arg_error(0);
		return (-1);
	}
	return (0);
}

void	arg_error(int flag)
{
	if (flag == 1)
	{
		printf("Error !\nExpected : ./philo (nb_philos > 0) time_to_die ");
		printf("time_to_eat time_to_sleep (optional arg: max_meals > 0)\n");
	}
}

int	print_state(t_data *data, char *msg)
{
	sem_wait(data->sem_print);
	if (someone_died())
	{
		sem_post(data->sem_print);
		return (1);
	}
	printf("%lu %d %s\n", get_time() - get_start_time(data),
		data->philo.id, msg);
	sem_post(data->sem_print);
	return (0);
}
