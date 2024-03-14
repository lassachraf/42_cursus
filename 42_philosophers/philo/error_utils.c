/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:46:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/03/14 01:07:21 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	else
		write(1, "Error\n", 5);
	exit(0);
}

void	ft_args_error(void)
{
	printf("Input error !\nExpected : ./philo [number_of_philosophers] ");
	printf("[time_to_die] [time_to_eat] [time_to_sleep] ");
	printf("[optional: max_meals]\n");
	exit(1);
}
