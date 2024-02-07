/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:02:41 by alassiqu          #+#    #+#             */
/*   Updated: 2024/02/05 13:28:53 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(t_so_long *game, int y, int x)
{
	if (game->flood_map[y][x] == 'E')
	{
		game->flood_map[y][x] = 'X';
		return ;
	}
	if (y < 0 || x < 0 || y >= game->flood_map_h || x >= game->flood_map_w
		|| (game->flood_map[y][x] != '0' && game->flood_map[y][x] != 'C'
			&& game->flood_map[y][x] != 'P'))
		return ;
	game->flood_map[y][x] = 'F';
	fill(game, y - 1, x);
	fill(game, y + 1, x);
	fill(game, y, x - 1);
	fill(game, y, x + 1);
}

void	flood_fill(t_so_long *game)
{
	fill(game, game->p_pos_y, game->p_pos_x);
}

void	check_flood_fill(t_so_long *game)
{
	flood_fill(game);
	check_coin_exit(game);
	if (game->flood_e_flag == 1 && game->flood_c_flag == 1)
	{
		write(1, "Invalid path, can't reach either all 'C' or 'E' !\n", 51);
		ft_free_maps(game);
		system("leaks so_long");
		exit(1);
	}
	else if (game->flood_e_flag == 1)
	{
		write(1, "Invalid path, can't reach 'E' !\n", 33);
		ft_free_maps(game);
		system("leaks so_long");
		exit(1);
	}
	else if (game->flood_c_flag == 1)
	{
		write(1, "Invalid path, can't reach 'C' !\n", 33);
		ft_free_maps(game);
		system("leaks so_long");
		exit(1);
	}
}

void	check_coin_exit(t_so_long *game)
{
	int	i;
	int	j;

	j = 0;
	game->flood_c_flag = 0;
	game->flood_e_flag = 0;
	while (j < game->flood_map_h)
	{
		i = 0;
		while (game->flood_map[j][i])
		{
			if (game->flood_map[j][i] == 'C')
				game->flood_c_flag = 1;
			else if (game->flood_map[j][i] == 'E')
				game->flood_e_flag = 1;
			i++;
		}
		j++;
	}
}
