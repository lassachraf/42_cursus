/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:11:12 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/21 10:14:46 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map_edges(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_w)
	{
		if (game->map[0][i] != '1' || game->map[game->map_h - 1][i] != '1')
			ft_map_error_1("Map should be surrounded by walls !\n");
		i++;
	}
	while (j < game->map_h)
	{
		if (game->map[j][0] != '1' || game->map[j][game->map_w - 1] != '1')
			ft_map_error_1("Map should be surrounded by walls !\n");
		j++;
	}
}

void	ft_check_map_elements(t_so_long *game)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'P' \
			&& game->map[i][j] != 'E' && game->map[i][j] != '1' \
			&& game->map[i][j] != '0' && game->map[i][j] != 'N')
				ft_map_error_2(game->map[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_check_map_coins(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->t_coins = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == 'C')
				game->t_coins++;
			j++;
		}
		i++;
	}
	if (game->t_coins == 0)
		ft_map_error_1("Map without coins isn't valid !\n");
}

void	ft_check_map_player(t_so_long *game)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		ft_map_error_1("Map without player isn't valid !!\n");
	if (count > 1)
		ft_map_error_1("Map with more than one player isn't valid !!\n");
}

void	ft_check_map_exit(t_so_long *game)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (game->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		ft_map_error_1("Map without exit isn't valid !!\n");
	if (count > 1)
		ft_map_error_1("Map with more than one exit isn't valid !!\n");
}
