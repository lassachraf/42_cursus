/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:37:11 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/20 18:03:03 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_error_1(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	ft_map_error_2(char c)
{
	write(1, "Invalid element \'", 18);
	write(1, &c, 1);
	write(1, "\' in map !\n", 12);
	exit(1);
}
