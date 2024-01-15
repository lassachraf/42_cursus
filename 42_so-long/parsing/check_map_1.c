/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:03:38 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/14 17:43:18 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_whole_map(t_so_long *game)
{
	ft_is_rectangular(&game);
	ft_check_map_edges(&game);
	ft_check_map_elements(&game);
	ft_check_map_player(&game);
	ft_check_map_exit(&game);
	game->coins = ft_check_map_coins(&game);
	return (1);
}

int	ft_is_rectangular(t_so_long *game)
{
	int i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[i]))
			return (ft_errors("The map isn't rectangular"), 0);
		i++;
	}
	return (1);
}

int	ft_count_height(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}
