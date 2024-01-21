/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:52:56 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/21 21:10:51 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initializing_images(t_so_long *game, int *j)
{
	j = 0;
	game->p_pos_x = 0;
	game->p_pos_y = 0;
	game->naruto = mlx_xpm_file_to_image(game->mlx, "assets/naruto/naruto.xpm",
			&game->img_w, &game->img_h);
	if (!game->naruto)
		ft_errors("Player image problem !\n");
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wall/wall.xpm",
			&game->img_w, &game->img_h);
	if (!game->wall)
		ft_errors("Wall image problem !\n");
	game->ramen = mlx_xpm_file_to_image(game->mlx, "assets/collect/ramen.xpm",
			&game->img_w, &game->img_h);
	if (!game->ramen)
		ft_errors("Ramen image problem !\n");
	game->floor = mlx_xpm_file_to_image(game->mlx, "assets/floor/floor.xpm",
			&game->img_w, &game->img_h);
	if (!game->floor)
		ft_errors("Floor image problem !\n");
	game->exit = mlx_xpm_file_to_image(game->mlx, "assets/exit/doors.xpm",
			&game->img_w, &game->img_h);
	if (!game->exit)
		ft_errors("Exit image problem\n");
	game->enemy = mlx_xpm_file_to_image(game->mlx, "assets/enemy/kurama_mode.xpm",
			&game->img_w, &game->img_h);
	if (!game->exit)
		ft_errors("Exit image problem\n");
	game->losing = mlx_xpm_file_to_image(game->mlx, "assets/finish/madara-win.xpm",
			&game->img_w, &game->img_h);
	if (!game->exit)
		ft_errors("Madara image problem\n");
	game->wining = mlx_xpm_file_to_image(game->mlx, "assets/finish/naruto-win.xpm",
			&game->img_w, &game->img_h);
	if (!game->exit)
		ft_errors("Naruto image problem\n");
}

void	puting_images(t_so_long *game)
{
	int	j;
	int	i;

	initializing_images(game, &j);
	while (j < game->map_h)
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, i
					* 60, j * 60);
			if (game->map[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, i
					* 60, j * 60);
			if (game->map[j][i] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor, i
					* 60, j * 60);
				mlx_put_image_to_window(game->mlx, game->win, game->naruto, i
					* 60, j * 60);
				game->p_pos_x = i;
				game->p_pos_y = j;
			}
			if (game->map[j][i] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor, i
					* 60, j * 60);
				mlx_put_image_to_window(game->mlx, game->win, game->ramen, i
					* 60, j * 60);
			}
			if (game->map[j][i] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor, i
					* 60, j * 60);
				mlx_put_image_to_window(game->mlx, game->win, game->exit, i
					* 60, j * 60);
			}
			if (game->map[j][i] == 'N')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor, i
					* 60, j * 60);
				mlx_put_image_to_window(game->mlx, game->win, game->enemy, i
					* 60, j * 60);
			}
			i++;
		}
		j++;
	}
}
#include <string.h>
void	ft_initializer(t_so_long *game, char **av)
{
	char *str = malloc(5);
	str = strcpy(str, "sala");
	ft_ber_extension(av[1]);
	game->map = ft_get_map(av[1]);
	game->map_h = ft_count_height(game);
	game->map_w = ft_strlen(game->map[0]);
	game->moves = 0;
	ft_is_rectangular(game);
	ft_check_map_edges(game);
	ft_check_map_elements(game);
	ft_check_map_coins(game);
	ft_check_map_player(game);
	ft_check_map_exit(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 60 * game->map_w, 60 * game->map_h,
			"Naruto so_long !");
	puting_images(game);
	mlx_string_put(game->mlx, game->win, 8, 4, 0x000000 , "Number of moves : ");
	mlx_string_put(game->mlx, game->win, 8, 20, 0x000000 , "Remaining ramen : ");
	mlx_hook(game->win, 2, 1L << 0, ft_moving, game);
	mlx_hook(game->win, 17, 0, ft_exit, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_so_long	*game;

	game = (t_so_long *)malloc(sizeof(t_so_long));
	if (!game)
		return (1);
	if (ac == 2)
	{
		ft_initializer(game, av);
	}
	else
		ft_arg_error();
	return (0);
}
