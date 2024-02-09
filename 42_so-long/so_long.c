/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:52:56 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/08 17:14:30 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_at_coordinates(t_so_long *game, int i, int j, void *image)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor, i * 60, j * 60);
	mlx_put_image_to_window(game->mlx, game->win, image, i * 60, j * 60);
}

void	put_objects_on_map(t_so_long *game, int i, int j)
{
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall, i * 60, j
			* 60);
	else if (game->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor, i * 60, j
			* 60);
	else if (game->map[j][i] == 'P')
	{
		put_image_at_coordinates(game, i, j, game->naruto_right);
		game->p_pos_x = i;
		game->p_pos_y = j;
	}
	else if (game->map[j][i] == 'C')
		put_image_at_coordinates(game, i, j, game->ramen);
	else if (game->map[j][i] == 'E')
	{
		game->doors_x = j;
		game->doors_y = i;
		put_image_at_coordinates(game, i, j, game->exit);
	}
	else if (game->map[j][i] == 'N')
		put_image_at_coordinates(game, i, j, game->enemy);
}

void	puting_images(t_so_long *game)
{
	int	j;
	int	i;

	j = 0;
	initializing_images(game);
	while (j < game->map_h)
	{
		i = 0;
		while (game->map[j][i])
		{
			put_objects_on_map(game, i, j);
			i++;
		}
		j++;
	}
}

void	ft_initializer(t_so_long *game, char **av)
{
	ft_ber_extension(av[1]);
	game->map = ft_get_map(av[1]);
	game->flood_map = ft_get_map(av[1]);
	game->map_h = ft_count_height(game);
	game->map_w = ft_strlen(game->map[0]);
	game->flood_map_h = game->map_h;
	game->flood_map_w = game->map_w;
	game->moves = 0;
	game->stop = 0;
	game->naruto_flag = 0;
	ft_check_whole_map(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 60 * game->map_w, 60 * game->map_h,
			"Naruto so_long !");
	puting_images(game);
	check_flood_fill(game);
	mlx_string_put(game->mlx, game->win, 8, 4, 0, "Number of moves : ");
	mlx_string_put(game->mlx, game->win, 8, 20, 0, "Remaining ramen : ");
	mlx_hook(game->win, 2, 1L << 0, ft_moving, game);
	mlx_hook(game->win, 17, 0, ft_exit, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_so_long	game;

	if (ac != 2)
		ft_arg_error();
	if (ac == 2)
		ft_initializer(&game, av);
	return (0);
}
