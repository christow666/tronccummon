/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:22:00 by christo           #+#    #+#             */
/*   Updated: 2022/11/29 05:50:02 by cperron          ###   ########.fr       */
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
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		x_x[20];
	int		x_y[20];
	int		x_ai[20];
	int		x_dx[20];
	int		x_dy[20];
	int		x_dd[20];
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

#endif