/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:20:28 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/14 18:06:21 by alassiqu         ###   ########.fr       */
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
	int		v_map;
	int		win_h;
	int		win_w;
	int		coins;
}				t_so_long;

// Libft functions !
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);

// Get_next_line function !
char	*get_next_line(int fd);

// Parsing functions !
int		ft_ber_extension(char *argv);
int		ft_check_map_edges(t_so_long *game);
int		ft_check_map_elements(t_so_long *game);
int		ft_check_map_coins(t_so_long *game);
int		ft_check_map_player(t_so_long *game);
int		ft_check_map_exit(t_so_long *game);
// char	**ft_get_map(char *argv);

// Errors functions !
void	ft_errors(char *s);

#endif