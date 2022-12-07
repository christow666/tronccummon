/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:17:36 by cperron           #+#    #+#             */
/*   Updated: 2022/12/06 22:18:00 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_init_ogro_rock(int x, int y, t_so_long *game)
{
	if (game->map[y][x] == 'O')
	{
		game->o_x[game->o_n] = x;
		game->o_y[game->o_n] = y;
		game->o_n++;
		ft_xpm_to_img("./O/O1.XPM", game);
	}
	if (game->map[y][x] == 'B')
	{
		game->b_x[game->b_n] = x;
		game->b_y[game->b_n] = y;
		ft_xpm_to_img("B.XPM", game);
		game->b_n++;
		game->b_max++;
	}
	return (0);
}

int	ft_init_bat_coin(int x, int y, t_so_long *game)
{
	if (game->map[y][x] == 'Z')
	{
		game->x_x[game->n_x] = x;
		game->x_y[game->n_x] = y;
		game->x_ai[game->n_x] = 1;
		game->x_dx[game->n_x] = 1;
		game->x_dxa[game->n_x] = 1;
		game->x_dy[game->n_x] = 0;
		ft_xpm_to_img("./Z/Z1.XPM", game);
		game->map[y][x] = '0';
		game->n_x++;
		game->x++;
	}
	if (game->map[y][x] == 'C')
	{
		game->c_x[game->c_n] = x;
		game->c_y[game->c_n] = y;
		game->c_i[game->c_n] = 0;
		ft_xpm_to_img("./C/C1.XPM", game);
		game->c_n++;
		game->coin_count++;
	}
	return (0);
}

int	ft_init_else(int x, int y, t_so_long *game)
{
	if (game->map[y][x] == '1')
		ft_xpm_to_img("1.XPM", game);
	if (game->map[y][x] == 'E')
	{
		game->e_x = x;
		game->e_y = y;
		ft_xpm_to_img("E.XPM", game);
	}
	if (game->map[y][x] == '0')
		ft_xpm_to_img("0.XPM", game);
	if (game->map[y][x] == 'P')
	{
		game->map[y][x] = '0';
		game->p_x = x;
		game->p_y = y;
		ft_xpm_to_img("./H/P1.XPM", game);
	}
	return (0);
}

int	ft_img_to_map(int x, int y, t_so_long *game)
{
	int	c;

	c = 0;
	game->win = mlx_new_window(game->mlx, game->div * 19,
			game->div * 10, "so_long");
	game->img = mlx_new_image(game->mlx, game->div * 10, game->div * 19);
	while (x < 19)
	{
		while (y < 10)
		{
			ft_init_ogro_rock(x, y, game);
			ft_init_bat_coin(x, y, game);
			ft_init_else(x, y, game);
			ft_img_to_win(x, y, game);
			y++;
		}
		y = 0;
		x++;
	}
	game->c_nn = game->coin_count;
	return (0);
}