/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraf <achraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:03:03 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/23 03:30:08 by achraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 5 || ac == 6)
	{
		parsing_input(&info, av);
		init_data(&info);
		start_simulation(&info);
		printf("Start simulation !\n");
		free_and_cleanup(&info);
	}
	else
		ft_args_error();
	return (0);
}
