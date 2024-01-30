/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:47:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/30 15:58:58 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	door_animation(t_so_long *game)
{
	static int	count;

	if (game->stop == 0 && game->t_coins == 0)
	{
		if (count < 20)
			game->exit = mlx_xpm_file_to_image(game->mlx,
				"assets/exit/doors-1.xpm", &game->img_w, &game->img_h);
		else if (count < 40)
			game->exit = mlx_xpm_file_to_image(game->mlx,
				"assets/exit/doors-2.xpm", &game->img_w, &game->img_h);
		else if (count < 60)
			game->exit = mlx_xpm_file_to_image(game->mlx,
				"assets/exit/doors-3.xpm", &game->img_w, &game->img_h);
		else if (count < 80)
			game->exit = mlx_xpm_file_to_image(game->mlx,
				"assets/exit/doors-4.xpm", &game->img_w, &game->img_h);
		else if (count < 100)
			game->exit = mlx_xpm_file_to_image(game->mlx,
				"assets/exit/doors-5.xpm", &game->img_w, &game->img_h);
		else if (count < 120)
			game->exit = mlx_xpm_file_to_image(game->mlx,
				"assets/exit/doors-6.xpm", &game->img_w, &game->img_h);
		if (count == 120)
		{
			game->stop = 1;
			printf("cc\n");
		}
		count++;
		put_image_at_coordinates(game, 15, 3, game->exit);
	}
	return (1);
}
