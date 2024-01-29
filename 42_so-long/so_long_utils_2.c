/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:51:23 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/25 21:58:43 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_up_and_down(t_so_long *game, int x, int y)
{
	if (game->naruto_flag == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->naruto_left,
			x * 60, y * 60);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->naruto_right,
			x * 60, y * 60);
}

void	ft_check_whole_map(t_so_long *game)
{
	ft_is_rectangular(game);
	ft_check_map_edges(game);
	ft_check_map_elements(game);
	ft_check_map_coins(game);
	ft_check_map_player(game);
	ft_check_map_exit(game);
	ft_is_rectangular(game);
	ft_check_map_edges(game);
	ft_check_map_elements(game);
	ft_check_map_coins(game);
	ft_check_map_player(game);
	ft_check_map_exit(game);
}
