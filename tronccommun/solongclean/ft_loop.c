/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:44:06 by christo           #+#    #+#             */
/*   Updated: 2022/12/01 00:07:40 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_bat_move( t_so_long *game)
{
	game->n_x = 0;
	while (game->n_x < game->x)
	{
		if (game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]][game->x_x[game->n_x] + game->x_dx[game->n_x]] == '1'
				|| game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]][game->x_x[game->n_x] + game->x_dx[game->n_x]]
				== 'E' || game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]][game->x_x[game->n_x] + game->x_dx[game->n_x]]
				== 'C' || game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]][game->x_x[game->n_x] + game->x_dx[game->n_x]]
				== 'e')
		{
			game->x_dx[game->n_x] *= -1;
			game->x_dy[game->n_x] = 0;
		}
		game->x_x[game->n_x] += game->x_dx[game->n_x];
		game->x_y[game->n_x] += game->x_dy[game->n_x];
		if (game->x_y[game->n_x] == game->p_y
			&& game->x_x[game->n_x] == game->p_x)
		{
			game->move_p = 1;
			ft_duck(game);
		}
		game->n_x++;
	}
	return (0);
}

int	ft_coin_anim(char *xpm, t_so_long *game)
{
	game->c_n = 0;
	while (game->c_n < game->c_nn)
	{
		ft_img_sprite_2(game->c_x[game->c_n], game->c_y[game->c_n], 0, "0.XPM", game);
		ft_img_sprite_2(game->c_x[game->c_n], game->c_y[game->c_n], 0, xpm, game);
		game->c_n++;
	}
	return (0);
}

int	ft_count_6(t_so_long *game)
{
	ft_coin_anim("./C/C4.xpm", game);
	ft_animation(4, "./H/P4.XPM", "./Z/Z4.XPM", game);
	ft_bat_move(game);
	ft_death_anim("./H/PD7.XPM", game);
	return (0);
}

int	ft_count_4(t_so_long *game)
{
	ft_coin_anim("./C/C3.xpm", game);
	ft_death_anim("./H/PD5.XPM", game);
	ft_animation(3, "./H/P3.XPM", "./Z/Z3.XPM", game);
	return (0);
}

int	ft_count_2(t_so_long *game)
{
	ft_coin_anim("./C/C2.xpm", game);
	ft_death_anim("./H/PD3.XPM", game);
	ft_animation(2, "./H/P2.XPM", "./Z/Z2.XPM", game);
	return (0);
}

int	ft_count_0(t_so_long *game)
{
	ft_coin_anim("./C/C1.xpm", game);
	ft_death_anim("./H/PD1.XPM", game);
	ft_animation(1, "./H/P1.XPM", "./Z/Z1.XPM", game);
	return (0);
}

int	ft_loop(t_so_long *game)
{
	if (game->anim_count == 0)
		ft_count_0(game);
	// if (game->anim_count == 1 * delay)
	if (game->anim_count == 2 * game->delay)
		ft_count_2(game);
	// if (game->anim_count == 3 * delay)
	if (game->anim_count == 4 * game->delay)
		ft_count_4(game);
	// if (game->anim_count == 5 * delay)
	if (game->anim_count == 6 * game->delay)
		ft_count_6(game);
	// if (game->anim_count == 7 * delay)
	if (game->move_p != 5)
	game->anim_count++;
	if (game->anim_count == 8 * game->delay)
		game->anim_count = 0;
	return (0);
}
