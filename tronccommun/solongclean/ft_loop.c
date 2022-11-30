/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:44:06 by christo           #+#    #+#             */
/*   Updated: 2022/11/30 06:51:34 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_xpm_to_img_2(char *imgf, t_so_long *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, imgf,
			&game->img_width, &game->img_height);
	return (0);
}

int	ft_img_to_win_2(int x, int y, int z, t_so_long *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->div * x + game->div4 * z, game->div * y);
	return (0);
}

int	ft_img_sprite_2(int x, int y, int z, char *xpm, t_so_long *game)
{
	ft_xpm_to_img_2(xpm, game);
	ft_img_to_win_2(x, y, z * game->x_dxa[game->n_x], game);
	return (0);
}

int	ft_check_anime_col(t_so_long *game)
{
	if (game->map[game->x_y[game->n_x]][game->x_x[game->n_x]
		+ game->x_dx[game->n_x]] == 'C' && game->anim_count == 0)
		return (1);
	if (game->map[game->x_y[game->n_x]][game->x_x[game->n_x]
		+ game->x_dx[game->n_x]] == '1' && game->anim_count == 0)
		return (1);
	if (ft_enemy_col(game->x_dxa[game->n_x], 0, game) == 1)
		return (1);
	return (0);
}

int	ft_animation(int z, char *P, char *Z, t_so_long *game)
{
	if (game->move_p == 0)
	{
		ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
		ft_img_sprite(game->p_x, game->p_y, P, game);
	}
	game->n_x = 0;
	while (game->n_x < game->x)
	{	
		if (ft_check_anime_col(game) == 1)
			game->x_dxa[game->n_x] *= -1;
		ft_img_sprite_2(game->x_x[game->n_x] + game->x_dxa[game->n_x],
			game->x_y[game->n_x], 0, "0.XPM", game);
		ft_img_sprite_2(game->x_x[game->n_x], game->x_y[game->n_x], 0,
			"0.XPM", game);
		game->n_x++;
	}
	game->n_x = 0;
	while (game->n_x < game->x)
	{	
		ft_img_sprite_2(game->x_x[game->n_x], game->x_y[game->n_x], z,
			Z, game);
		game->n_x++;
	}
	return (0);
}

int	ft_loop(t_so_long *game)
{
	if (game->anim_count == 0)
	{
		if (game->move_p == 1)
		{
			ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
			ft_img_sprite(game->p_x, game->p_y, "./H/PD1.xpm", game);
		}
		ft_animation(1, "./H/P1.xpm", "./Z/Z1.xpm", game);
		// ft_enemy_ai(game);
	}
	if (game->anim_count == 1500)
	{
		if (game->move_p == 1)
		{
			ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
			ft_img_sprite(game->p_x, game->p_y, "./H/PD3.xpm", game);
		}
		ft_animation(2, "./H/P2.xpm", "./Z/Z2.xpm", game);
	}
	if (game->anim_count == 3000)
	{
		if (game->move_p == 1)
		{
			ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
			ft_img_sprite(game->p_x, game->p_y, "./H/PD5.xpm", game);
		}
		// ft_enemy_ai(game);
		ft_animation(3, "./H/P3.xpm", "./Z/Z3.xpm", game);
	}
	if (game->anim_count == 4500)
	{
		if (game->move_p == 1)
		{
			ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
			ft_img_sprite(game->p_x, game->p_y, "./H/PD7.xpm", game);
			game->move_p = 2;
		}
		ft_animation(4, "./H/P4.xpm", "./Z/Z4.xpm", game);
		ft_enemy_ai(game);
	}
	game->anim_count++;
	if (game->anim_count == 6000)
		game->anim_count = 0;
	return (0);
}
