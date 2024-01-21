/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:44:13 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/21 06:22:29 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_ber_extension(char *argv)
{
	if (access(argv, F_OK) == 0)
	{
		if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 5) == 0)
			return (1);
		else
		{
			write(1, "Extension file error\n", 22);
			exit(1);
		}
	}
	else
	{
		write(1, "Map file doesn't exist\n", 24);
		exit(1);
	}
	return (0);
}
