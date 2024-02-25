/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:48:41 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/25 10:08:19 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_error_args(char **s)
{
	int	i;

	i = 0;
	(void)s;
	// while (s[i])
	// {
	// 	free(s[i]);
	// 	i++;
	// }
	// free(s);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_error_stack(t_stack **a)
{
	if (*a)
		free(*a);
	*a = NULL;
	ft_putstr_fd("Error\n", 2);
	exit(1);
}