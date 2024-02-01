/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:47:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/01 16:06:54 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	door_animation(t_so_long *game)
{
	static int	count;

	if (count < 20)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"textures/exit/doors-1.xpm", &game->img_w, &game->img_h);
	else if (count < 40)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"textures/exit/doors-2.xpm", &game->img_w, &game->img_h);
	else if (count < 60)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"textures/exit/doors-3.xpm", &game->img_w, &game->img_h);
	else if (count < 80)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"textures/exit/doors-4.xpm", &game->img_w, &game->img_h);
	else if (count < 100)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"textures/exit/doors-5.xpm", &game->img_w, &game->img_h);
	else if (count < 120)
		game->exit = mlx_xpm_file_to_image(game->mlx,
				"textures/exit/doors-6.xpm", &game->img_w, &game->img_h);
	if (count == 120)
		game->stop = 1;
	put_image_at_coordinates(game, game->doors_y, game->doors_x, game->exit);
	count++;
	return (1);
}

int	put_enemy(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game->enemy)
		ft_errors("Enemy image error !\n");
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
				put_image_at_coordinates(game, j, i, game->enemy);
			j++;
		}
		i++;
	}
	return (1);
}

int	enemy_animation(t_so_long *game)
{
	static int	count;

	if (count < 20)
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"textures/enemy/itachi-1.xpm", &game->img_w, &game->img_h);
	else if (count < 40)
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"textures/enemy/itachi-2.xpm", &game->img_w, &game->img_h);
	else if (count < 60)
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"textures/enemy/itachi-3.xpm", &game->img_w, &game->img_h);
	else if (count < 80)
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"textures/enemy/itachi-4.xpm", &game->img_w, &game->img_h);
	else if (count < 100)
		game->enemy = mlx_xpm_file_to_image(game->mlx,
				"textures/enemy/itachi-5.xpm", &game->img_w, &game->img_h);
	if (count == 100)
		count = 0;
	put_enemy(game);
	count++;
	return (1);
}

int	animation(t_so_long *game)
{
	if (game->stop == 0 && game->t_coins == 0)
		door_animation(game);
	enemy_animation(game);
	return (1);
}
