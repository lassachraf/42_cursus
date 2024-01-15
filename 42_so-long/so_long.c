/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:20:28 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/14 18:06:06 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// char	**ft_get_map(char *argv)
// {
// 	char	*full_map;
// 	char	*map;
// 	char	*line;
// 	int		fd;

// 	map = NULL;
// 	fd = open(argv, O_RDONLY);
// 	if (fd == -1)
// 		return (ft_errors("Error opening map file"), NULL);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		full_map = ft_strjoin(map, line);
// 		printf("%s", full_map);
// 		free(line);
// 		free(map);
// 	}
// 	return (ft_split(full_map, '\n'));
// }

void	ft_constructer(t_so_long *game)
{
	game->mlx = mlx_init();
	game->win_h = ft_count_height(&game);
	game->win_w = ft_strlen(game->map[0]);
    game->v_map = ft_check_whole_map(game->map, game->win_w, game->win_h);
	game->win = mlx_new_window(game->mlx, 55 * game->win_h, 55 * game->win_w, "Naruto so_long !");
}

int	main(int argc, char **argv)
{
	t_so_long	*game;
	int			i;
	int			j;

	if (argc == 2)
	{
		ft_ber_extension(argv[1]);
		game->map = ft_get_map(argv[1]);
        printf("s[0] => %s\n", game->map[0]);
        game->mlx = mlx_init();
        game->win = mlx_new_window(game->mlx, 55 * game->win_h, 55 * game->win_w, "Naruto so_long !");
        // ft_constructer(&game);
		// mlx_put_image_to_window(game->mlx, game->win, game->img, 50, 50);
		mlx_loop(game->mlx);
	}
	else
		ft_errors("Bad arguments, expecting 2 args");
}
