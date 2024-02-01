/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:14:48 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/31 14:22:59 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_errors(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	ft_arg_error(void)
{
	write(1, "Bad number of args, expected 2 arguments !\n", 44);
	exit(1);
}
