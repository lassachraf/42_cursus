/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:34:21 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/25 21:54:24 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving_up(t_so_long *game)
{
	if (game->map[game->p_pos_y - 1][game->p_pos_x] == 'C')
	{
		game->map[game->p_pos_y - 1][game->p_pos_x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, (game->p_pos_y - 1) * 60);
		check_for_up_and_down(game, game->p_pos_x, game->p_pos_y - 1);
		game->p_pos_y--;
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y - 1][game->p_pos_x] == 'E')
		check_exit(game, game->p_pos_y - 1, game->p_pos_x);
	else if (game->map[game->p_pos_y - 1][game->p_pos_x] == 'N')
		ft_lose_exit(game);
	else if (game->map[game->p_pos_y - 1][game->p_pos_x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		check_for_up_and_down(game, game->p_pos_x, game->p_pos_y - 1);
		game->p_pos_y--;
	}
	game->moves++;
}

void	moving_down(t_so_long *game)
{
	if (game->map[game->p_pos_y + 1][game->p_pos_x] == 'C')
	{
		game->map[game->p_pos_y + 1][game->p_pos_x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, (game->p_pos_y + 1) * 60);
		check_for_up_and_down(game, game->p_pos_x, game->p_pos_y + 1);
		game->p_pos_y++;
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y + 1][game->p_pos_x] == 'E')
		check_exit(game, game->p_pos_y + 1, game->p_pos_x);
	else if (game->map[game->p_pos_y + 1][game->p_pos_x] == 'N')
		ft_lose_exit(game);
	else if (game->map[game->p_pos_y + 1][game->p_pos_x] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		check_for_up_and_down(game, game->p_pos_x, game->p_pos_y + 1);
		game->p_pos_y++;
	}
	game->moves++;
}

void	moving_right(t_so_long *game)
{
	game->naruto_flag = 0;
	if (game->map[game->p_pos_y][game->p_pos_x + 1] == 'C')
	{
		game->map[game->p_pos_y][game->p_pos_x + 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			(game->p_pos_x + 1) * 60, game->p_pos_y * 60);
		check_for_up_and_down(game, game->p_pos_x + 1, game->p_pos_y);
		game->p_pos_x++;
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y][game->p_pos_x + 1] == 'E')
		check_exit(game, game->p_pos_y, game->p_pos_x + 1);
	else if (game->map[game->p_pos_y][game->p_pos_x + 1] == 'N')
		ft_lose_exit(game);
	else if (game->map[game->p_pos_y][game->p_pos_x + 1] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		check_for_up_and_down(game, game->p_pos_x + 1, game->p_pos_y);
		game->p_pos_x++;
	}
	game->moves++;
}

void	moving_left(t_so_long *game)
{
	game->naruto_flag = 1;
	if (game->map[game->p_pos_y][game->p_pos_x - 1] == 'C')
	{
		game->map[game->p_pos_y][game->p_pos_x - 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			(game->p_pos_x - 1) * 60, game->p_pos_y * 60);
		check_for_up_and_down(game, game->p_pos_x - 1, game->p_pos_y);
		game->p_pos_x--;
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y][game->p_pos_x - 1] == 'E')
		check_exit(game, game->p_pos_y, game->p_pos_x - 1);
	else if (game->map[game->p_pos_y][game->p_pos_x - 1] == 'N')
		ft_lose_exit(game);
	else if (game->map[game->p_pos_y][game->p_pos_x - 1] != 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		check_for_up_and_down(game, game->p_pos_x - 1, game->p_pos_y);
		game->p_pos_x--;
	}
	game->moves++;
}

int	ft_moving(int keycode, t_so_long *game)
{
	int	i;

	i = 1;
	if (keycode == 53)
		ft_exit(game);
	else if ((keycode == W_KEY || keycode == UP_KEY)
		&& game->map[game->p_pos_y - 1][game->p_pos_x] != '1')
		moving_up(game);
	else if ((keycode == A_KEY || keycode == LEFT_KEY)
		&& game->map[game->p_pos_y][game->p_pos_x - 1] != '1')
		moving_left(game);
	else if ((keycode == D_KEY || keycode == RIGHT_KEY)
		&& game->map[game->p_pos_y][game->p_pos_x + 1] != '1')
		moving_right(game);
	else if ((keycode == S_KEY || keycode == DOWN_KEY)
		&& game->map[game->p_pos_y + 1][game->p_pos_x] != '1')
		moving_down(game);
	else
		i = 0;
	if (i == 1)
		ft_printing(game);
	return (0);
}
