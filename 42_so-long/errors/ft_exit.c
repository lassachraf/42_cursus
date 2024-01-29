/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:40:29 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/25 21:43:45 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_exit(t_so_long *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->naruto_left);
	mlx_destroy_image(game->mlx, game->naruto_right);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->ramen);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->enemy);
	mlx_destroy_image(game->mlx, game->wining);
	mlx_destroy_image(game->mlx, game->losing);
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	i = 0;
	while (game->flood_map[i])
		free(game->flood_map[i++]);
	free(game->flood_map);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	exit(0);
	return (0);
}

void	ft_win_exit(t_so_long *game)
{
	game->clear = 1;
	ft_clear(game);
	write(1, "You won !\n", 11);
	ft_exit(game);
}

void	ft_lose_exit(t_so_long *game)
{
	game->clear = 3;
	ft_clear(game);
	write(1, "You lose !\n", 12);
	ft_exit(game);
}

int	ft_clear(t_so_long *game)
{
	int	i;

	i = 0;
	if (game->clear == 1 || game->clear == 3)
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->clear == 1)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->losing, 0, 0);
			game->clear = 2;
		}
		else if (game->clear == 3)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->losing, 0, 0);
			game->clear = 2;
		}
	}
	else if (game->clear == 2)
	{
		mlx_clear_window(game->mlx, game->win);
	}
	game->clear = 0;
	return (0);
}
