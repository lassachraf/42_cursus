/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:25:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/01 16:03:30 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checking_images(t_so_long *game)
{
	if (!game->naruto_right || !game->naruto_left)
		ft_errors("Player image problem !\n");
	else if (!game->wall)
		ft_errors("Wall image problem !\n");
	else if (!game->ramen)
		ft_errors("Ramen image problem !\n");
	else if (!game->floor)
		ft_errors("Floor image problem !\n");
	else if (!game->exit)
		ft_errors("Exit image problem !\n");
	else if (!game->enemy)
		ft_errors("Enemy image problem !\n");
}

void	initializing_images(t_so_long *game)
{
	game->naruto_right = mlx_xpm_file_to_image(game->mlx,
			"textures/naruto/naruto_right.xpm", &game->img_w, &game->img_h);
	game->naruto_left = mlx_xpm_file_to_image(game->mlx,
			"textures/naruto/naruto_left.xpm", &game->img_w, &game->img_h);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall/wall.xpm", &game->img_w, &game->img_h);
	game->ramen = mlx_xpm_file_to_image(game->mlx,
			"textures/collect/ramen.xpm", &game->img_w, &game->img_h);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor/floor.xpm", &game->img_w, &game->img_h);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/doors.xpm", &game->img_w, &game->img_h);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy/itachi-0.xpm", &game->img_w, &game->img_h);
	checking_images(game);
}

void	ft_printing(t_so_long *game)
{
	char	*moves;
	char	*rem_coins;

	moves = ft_itoa(game->moves);
	rem_coins = ft_itoa(game->t_coins);
	write(1, "Number of Moves : ", 19);
	write(1, moves, ft_strlen_2(moves));
	write(1, " \n", 2);
	mlx_put_image_to_window(game->mlx, game->win, game->wall, 3 * 60, 0 * 60);
	mlx_put_image_to_window(game->mlx, game->win, game->wall, 4 * 60, 0 * 60);
	mlx_put_image_to_window(game->mlx, game->win, game->wall, 5 * 60, 0 * 60);
	mlx_string_put(game->mlx, game->win, 200, 4, 0, moves);
	mlx_string_put(game->mlx, game->win, 200, 20, 0, rem_coins);
	free(moves);
	free(rem_coins);
}

void	check_exit(t_so_long *game, int y, int x)
{
	if (game->map[y][x] == 'E' && game->t_coins == 0)
		ft_win_exit(game);
	else
	{
		game->moves--;
		return ;
	}
}

void	check_enemy(t_so_long *game, int y, int x)
{
	if (game->map[y][x] == 'N')
		ft_lose_exit(game);
	else
	{
		game->moves--;
		return ;
	}
}
