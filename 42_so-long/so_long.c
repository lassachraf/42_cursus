/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:20:28 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/13 20:41:59 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_so_long game;

	if (argc == 2)
	{
		ft_ber_extension(argv[1]);
		game.map = ft_get_map(argv[1]);
        
		check_map(&game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, 500, 500, "NARUTO");
		mlx_loop(game.mlx);
	}
}