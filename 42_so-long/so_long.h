/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:34:50 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/27 20:44:56 by alassiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "42_get-next-line/get_next_line.h"

# define ESC_KEY 53
# define W_KEY 13
# define UP_KEY 126
# define A_KEY 0
# define LEFT_KEY 123
# define S_KEY 1
# define DOWN_KEY 125
# define D_KEY 2
# define RIGHT_KEY 124

typedef struct s_so_long
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*floor;
	void	*naruto;
	void	*naruto_left;
	void	*naruto_right;
	int		naruto_flag;
	void	*wall;
	void	*ramen;
	void	*exit;
	void	*enemy;
	void	*wining;
	void	*losing;

	char	**map;
	int		map_h;
	int		map_w;
	char	**flood_map;
	int		flood_map_h;
	int		flood_map_w;
	int		flood_c_flag;
	int		flood_e_flag;
	int		clear;
	int		img_h;
	int		img_w;
	int		t_coins;
	size_t	moves;

	int		p_pos_x;
	int		p_pos_y;
}				t_so_long;

// Libft needed functions !

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr_2(const char *s, int c);
size_t	ft_strlen_2(const char *s);
char	*ft_strjoin_2(char const *s1, char const *s2);
char	*ft_itoa(size_t n);

// Parsing functions ! 

int		ft_ber_extension(char *argv);
char	**ft_get_map(char *s);
void	ft_check_map_edges(t_so_long *game);
void	ft_check_map_elements(t_so_long *game);
void	ft_check_map_coins(t_so_long *game);
void	ft_check_map_player(t_so_long *game);
void	ft_check_map_exit(t_so_long *game);
void	ft_is_rectangular(t_so_long *game);
int		ft_count_height(t_so_long *game);

// Errors functions !

void	ft_errors(char *s);
void	ft_arg_error(void);
int		ft_exit(t_so_long *game);
void	ft_win_exit(t_so_long *game);
void	ft_lose_exit(t_so_long *game);
void	ft_map_error_1(char *s);
void	ft_map_error_2(char c);

// So_long utils !

int		ft_moving(int keycode, t_so_long *game);
void	check_exit(t_so_long *game, int y, int x);
void	check_enemy(t_so_long *game, int y, int x);
void	initializing_images(t_so_long *game);
void	puting_images(t_so_long *game);
void	ft_printing(t_so_long *game);
int		ft_clear(t_so_long *game);
void	check_flood_fill(t_so_long *game);
void	check_coin_exit(t_so_long *game);
void	ft_check_whole_map(t_so_long *game);
void	ft_initializer(t_so_long *game, char **av);
void	check_for_up_and_down(t_so_long *game, int x, int y);
int		door_animation(t_so_long *game);

#endif