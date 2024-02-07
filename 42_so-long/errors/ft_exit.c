/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:40:29 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/07 18:28:42 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_maps(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	i = 0;
	while (game->flood_map[i])
		free(game->flood_map[i++]);
	free(game->flood_map);
}

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
	ft_free_maps(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	system("leaks so_long");
	exit(0);
	return (0);
}

void	ft_win_exit(t_so_long *game)
{
	write(1, "You won !\n", 11);
	ft_exit(game);
}

void	ft_lose_exit(t_so_long *game)
{
	write(1, "You lose !\n", 12);
	ft_exit(game);
}
