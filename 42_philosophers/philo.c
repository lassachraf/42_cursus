/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:03:03 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/10 20:48:46 by alassiqu         ###   ########.fr       */
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
		// start main things ;
		// similution_start(&info);
		// free memory ;
		// free_and_cleanup(&info);
	}
	else
	{
		write(1, "Input error:\n", 13);
		exit(1);
	}
}
