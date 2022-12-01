/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:22:00 by christo           #+#    #+#             */
/*   Updated: 2022/12/01 00:06:45 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
// # include "./mlx/mlx_int.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct so_long
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	int		anim_count;
	int		move_count;
	int		coin_count;
	int		div;
	int		div4;
	int		delay;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		x_x[20];
	int		x_y[20];
	int		x_ai[20];
	int		x_dx[20];
	int		x_dy[20];
	int		x_dxa[20];
	int		c_x[20];
	int		c_y[20];
	int		x_m[20];
	int		c_n;
	int		c_nn;
	int		n_x;
	int		x;
	int		move_p;
	char	map[20][20];
}	t_so_long;

int	ft_read_map(t_so_long *game);
int	ft_xpm_to_img(char *imgf, t_so_long *game);
int	ft_img_to_win(int i, int j, t_so_long *game);
int	ft_enemy_ai(t_so_long *game);
int	ft_duck(t_so_long *game);
int	ft_img_sprite(int x, int y, char *xpm, t_so_long *game);
int	ft_loop(t_so_long *game);
int	ft_img_switch(int x, int y, t_so_long *game);
int	ft_img_sprite(int x, int y, char *xpm, t_so_long *game);
int	ft_death(t_so_long *game);
int	ft_open_exit(t_so_long *game);
int	ft_game_over(t_so_long *game);
int	ft_exit_game(t_so_long *game);
int	ft_enemy_col(int x, int y, t_so_long *game);
int	key_hook(int keycode, t_so_long *game);
int	ft_animation(int z, char *P, char *Z, t_so_long *game);
int	ft_death_anim(char *xpm, t_so_long *game);
int	ft_img_sprite_2(int x, int y, int z, char *xpm, t_so_long *game);

#endif