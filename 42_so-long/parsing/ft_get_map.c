/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:28:30 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/13 18:32:26 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_get_map(char *argv)
{
	char	*full_map;
	char	*map;
	char	*line;
	int		fd;

	map = NULL;
	line = "";
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_errors("Error opening map file"), NULL);
	printf("im here wallah\n");
	printf("this the line %s\n", line);
	while (1)
	{
		printf("cc ana hona\n");
		line = get_next_line(fd);
		if (!line)
		{
			printf("line 3awtani %s\n", line);
			printf("hani khrejt\n");
			break ;
		}
		full_map = ft_strjoin(map, line);
		free(line);
		free(map);
	}
	return (ft_split(full_map, '\n'));
}

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		char **map = ft_get_map(argv[1]);
// 		int i = 0;
// 		while (i < 5)
// 		{
// 			printf("%s\n", map[i++]);
// 		}
// 	}
// }