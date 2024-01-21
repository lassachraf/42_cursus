/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:34:21 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/21 21:17:12 by alassiqu         ###   ########.fr       */
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
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			game->p_pos_x * 60, (game->p_pos_y - 1) * 60);
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y - 1][game->p_pos_x] == 'E'
		&& game->t_coins == 0)
		ft_win_exit(game);
	else if (game->map[game->p_pos_y - 1][game->p_pos_x] == 'N')
	{
		printf("You lose !!");
		exit(1);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			game->p_pos_x * 60, (game->p_pos_y - 1) * 60);
	}
	game->p_pos_y--;
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
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			game->p_pos_x * 60, (game->p_pos_y + 1) * 60);
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y + 1][game->p_pos_x] == 'E'
		&& game->t_coins == 0)
		ft_win_exit(game);
	else if (game->map[game->p_pos_y + 1][game->p_pos_x] == 'N')
	{
		printf("You lose !!");
		exit(1);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			game->p_pos_x * 60, (game->p_pos_y + 1) * 60);
	}
	game->p_pos_y++;
	game->moves++;
}

void	moving_right(t_so_long *game)
{
	if (game->map[game->p_pos_y][game->p_pos_x + 1] == 'C')
	{
		game->map[game->p_pos_y][game->p_pos_x + 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			(game->p_pos_x + 1) * 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			(game->p_pos_x + 1) * 60, game->p_pos_y * 60);
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y][game->p_pos_x + 1] == 'E'
		&& game->t_coins == 0)
		ft_win_exit(game);
	else if (game->map[game->p_pos_y][game->p_pos_x + 1] == 'N')
	{
		printf("You lose !!");
		exit(1);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			(game->p_pos_x + 1) * 60, game->p_pos_y * 60);
	}
	game->p_pos_x++;
	game->moves++;
}

void	moving_left(t_so_long *game)
{
	if (game->map[game->p_pos_y][game->p_pos_x - 1] == 'C')
	{
		game->map[game->p_pos_y][game->p_pos_x - 1] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->floor,
			(game->p_pos_x - 1) * 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			(game->p_pos_x - 1) * 60, game->p_pos_y * 60);
		game->t_coins--;
	}
	else if (game->map[game->p_pos_y][game->p_pos_x - 1] == 'E'
		&& game->t_coins == 0)
		ft_win_exit(game);
	else if (game->map[game->p_pos_y][game->p_pos_x - 1] == 'N')
	{
		printf("You lose !!");
		ft_exit(game);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor, game->p_pos_x
			* 60, game->p_pos_y * 60);
		mlx_put_image_to_window(game->mlx, game->win, game->naruto,
			(game->p_pos_x - 1) * 60, game->p_pos_y * 60);
	}
	game->p_pos_x--;
	game->moves++;
}

void	ft_print_moves(t_so_long *game)
{
	char	*moves;
	char	*rem_coins;

	moves = ft_itoa(game->moves);
	rem_coins = ft_itoa(game->t_coins);
	mlx_put_image_to_window(game->mlx, game->win, game->wall,
			3 * 60, 0 * 60);
	mlx_string_put(game->mlx, game->win, 200, 4, 0x000000, moves);
	mlx_string_put(game->mlx, game->win, 200, 20, 0x000000, rem_coins);
	free(moves);
	free(rem_coins);
}

int	ft_moving(int keycode, t_so_long *game)
{
	if (keycode == 53)
		ft_exit(game);
	else if ((keycode == W_KEY || keycode == UP_KEY) && game->map[game->p_pos_y
		- 1][game->p_pos_x] != '1')
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
	ft_print_moves(game);
	return (0);
}
