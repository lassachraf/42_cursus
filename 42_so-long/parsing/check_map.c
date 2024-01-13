/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:03:38 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/13 17:13:46 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_whole_map(char **map, int cols, int rows)
{
	int	coins;

	ft_check_map_edges(map, cols, rows);
	ft_check_map_elements(map, cols, rows);
	ft_check_map_player(map, cols, rows);
	ft_check_map_exit(map, cols, rows);
	coins = ft_check_map_coins(map, cols, rows);
	return (coins);
}
