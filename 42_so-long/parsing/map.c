/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:15:11 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/13 17:08:29 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_map_edges(char **map, int cols, int rows)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cols)
	{
		if (map[0][i] != 1 || map[rows - 1][i] != 1)
			return (ft_errors("Map should be surrounded by walls !!"), 0);
		i++;
	}
	while (j < rows)
	{
		if (map[j][0] != 1 || map[j][cols - 1] != 1)
			return (ft_errors("Map should be surrounded by walls !!"), 0);
		j++;
	}
	return (1);
}

int	ft_check_map_elements(char **map, int cols, int rows)
{
	char	*s;
	int		count;
	int		i;
	int		j;

	s = "Map shouldn't have elements other than '0', '1', 'P', 'C' and 'E' !!";
	count = 0;
	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != '1' && map[i][j] != '0') // add \n and N
				return (ft_errors(s), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_map_coins(char **map, int cols, int rows)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (ft_errors("Map without coins isn't valid !!"), 0);
	return (count);
}

int	ft_check_map_player(char **map, int cols, int rows)
{
	char	*s;
	int		count;
	int		i;
	int		j;

	s = "Map without/with more than one player isn't valid !!";
	count = 0;
	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0 || count > 1)
		return (ft_errors(s), 0);
	return (1);
}

int	ft_check_map_exit(char **map, int cols, int rows)
{
	char	*s;
	int		count;
	int		i;
	int		j;

	s = "Map without/with more than one exit isn't valid !!";
	count = 0;
	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0 || count > 1)
		return (ft_errors(s), 0);
	return (1);
}
