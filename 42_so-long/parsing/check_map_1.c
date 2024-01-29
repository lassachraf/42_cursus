/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:05:19 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/26 10:47:46 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_is_rectangular(t_so_long *game)
{
	int	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[i]))
		{
			write(1, "The map isn't rectangular !\n", 29);
			exit(1);
		}
		i++;
	}
}

int	ft_count_height(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	return (i);
}

static void	check_for_lines(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			ft_errors("Map isn't valid !\n");
		i++;
	}
}

static char	*ft_free_2(char *s, char *s1)
{
	if (s1)
		free(s1);
	return (s);
}

char	**ft_get_map(char *s)
{
	char	**splited;
	char	*all_lines;
	char	*line;
	int		fd;

	all_lines = NULL;
	splited = NULL;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_errors("Opening map file error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n')
			ft_errors("Map isn't valid !");
		all_lines = ft_free_2(ft_strjoin(all_lines, line), all_lines);
		free(line);
	}
	if (!all_lines)
		ft_map_error_1("Empty map file error !");
	check_for_lines(all_lines);
	splited = ft_split(all_lines, '\n');
	return (free(all_lines), splited);
}
