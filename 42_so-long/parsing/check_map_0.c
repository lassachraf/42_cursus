/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game->map_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:15:11 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/14 17:36:12 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_map_edges(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->win_w)
	{
		if (game->map[0][i] != 1 || game->map[game->win_h - 1][i] != 1)
			return (ft_errors("game->map should be surrounded by walls !!"), 0);
		i++;
	}
	while (j < game->win_h)
	{
		if (game->map[j][0] != 1 || game->map[j][game->win_w - 1] != 1)
			return (ft_errors("game->map should be surrounded by walls !!"), 0);
		j++;
	}
	return (1);
}

int	ft_check_map_elements(t_so_long *game)
{
	char	*s;
	int		count;
	int		i;
	int		j;

	s = "Map shouldn't have elements other than '0', '1', 'P', 'C', 'N' and 'E' !!";
	count = 0;
	i = 0;
	j = 0;
	while (i < game->win_h)
	{
		j = 0;
		while (j < game->win_w)
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'N')
				return (ft_errors(s), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_map_coins(t_so_long *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (i < game->win_h)
	{
		j = 0;
		while (j < game->win_w)
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (ft_errors("game->map without coins isn't valid !!"), 0);
	return (count);
}

int	ft_check_map_player(t_so_long *game)
{
	char	*s;
	int		count;
	int		i;
	int		j;

	s = "Map without/with more than one player isn't valid !!";
	count = 0;
	i = 0;
	j = 0;
	while (i < game->win_h)
	{
		j = 0;
		while (j < game->win_w)
		{
			if (game->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0 || count > 1)
		return (ft_errors(s), 0);
	return (1);
}

int	ft_check_map_exit(t_so_long *game)
{
	char	*s;
	int		count;
	int		i;
	int		j;

	s = "Map without/with more than one exit isn't valid !!";
	count = 0;
	i = 0;
	j = 0;
	while (i < game->win_h)
	{
		j = 0;
		while (j < game->win_w)
		{
			if (game->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0 || count > 1)
		return (ft_errors(s), 0);
	return (1);
}
