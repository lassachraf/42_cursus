/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:34:50 by alassiqu          #+#    #+#             */
/*   Updated: 2024/01/21 21:15:42 by alassiqu         ###   ########.fr       */
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
	void	*wall;
	void	*ramen;
	void	*exit;
	void	*enemy;
	void	*wining;
	void	*losing;

	char	**map;
	int		v_map;
	int		map_h;
	int		map_w;
	int		img_h;
	int		img_w;
	int		t_coins;
	int		moves;

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
char	*ft_itoa(int n);

// Ber extension check !

int		ft_ber_extension(char *argv);

// Map parsing functions ! 

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
void	ft_map_error_1(char *s);
void	ft_map_error_2(char c);

// Moving functions !

int		ft_moving(int keycode, t_so_long *game);
int		ft_exit(t_so_long *game);
void	ft_free_map(t_so_long *game);
void	puting_images(t_so_long *game);
void	ft_print_moves(t_so_long *game);
void	ft_win_exit(t_so_long *game);

#endif