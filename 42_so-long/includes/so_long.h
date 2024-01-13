/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:20:28 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/13 21:44:14 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
// # include "../42_get-next-line/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct so_long
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*floor;
	void	*naruto;
	void	*wall;
	void	*kurama;

	char	**map;
}				t_so_long;

// Libft functions !
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

// Get_next_line function !
char	*get_next_line(int fd);

// Parsing functions !
int		ft_ber_extension(char *argv);
int		ft_check_map_edges(char **map, int cols, int rows);
int		ft_check_map_elements(char **map, int cols, int rows);
int		ft_check_map_coins(char **map, int cols, int rows);
int		ft_check_map_player(char **map, int cols, int rows);
int		ft_check_map_exit(char **map, int cols, int rows);
char	**ft_get_map(char *argv);

// Errors functions !
void	ft_errors(char *s);

#endif