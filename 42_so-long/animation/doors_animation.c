/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:47:46 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/29 17:15:12 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	door_animation(t_so_long *game)
{
	static int	count;

	while (count < 200)
	{
		printf("count => %d\n", count);
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
		else if (count < 140)
			game->exit = mlx_xpm_file_to_image(game->mlx,
				"assets/exit/doors-7.xpm", &game->img_w, &game->img_h);
		count++;
		puting_images(game);
	}
	return (1);
}
