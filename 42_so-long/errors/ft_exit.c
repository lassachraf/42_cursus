/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:40:29 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/21 21:29:44 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_map(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

int	ft_exit(t_so_long *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_map(game);
	exit(0);
	return (0);
}

void	ft_win_exit(t_so_long *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->wining, 0, 0);
	ft_exit(game);
}

void	ft_lose_exit(t_so_long *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->wining, 0, 0);
	ft_exit(game);
}