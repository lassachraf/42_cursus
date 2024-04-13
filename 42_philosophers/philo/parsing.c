/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:15:50 by alassiqu          #+#    #+#             */
/*   Updated: 2024/04/13 21:15:51 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		arg_error();
		return (-1);
	}
	if (ft_atol(av[1]) <= 0 || (ac == 6 && ft_atol(av[5]) <= 0))
		return (-1);
	return (0);
}

void	arg_error(void)
{
	printf("Error !\nExpected : ./philo (nb_philos > 0) time_to_die ");
	printf("time_to_eat time_to_sleep (optional arg: max_meals > 0)\n");
}

void	print_state(t_data *data, int id, char *msg)
{
	long unsigned int	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->print_mutex);
	if (get_keep_iter(data))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}
