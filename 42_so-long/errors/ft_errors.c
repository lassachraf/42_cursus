/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:14:48 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/22 10:44:32 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_errors(char *s)
{
	if (!*s)
		s = "ERROR";
	perror(s);
	exit(1);
}

void	ft_arg_error(void)
{
	write(1, "Bad number of args, expected 2 arguments !\n", 44);
	exit(1);
}
