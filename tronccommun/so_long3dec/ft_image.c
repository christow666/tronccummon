/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:43:00 by christo           #+#    #+#             */
/*   Updated: 2022/12/08 00:00:29 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_img_sprite_2(int x, int y, int z, char *xpm, t_so_long *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, xpm,
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->div * x + game->div4 * z, game->div * y);
	mlx_destroy_image(game->mlx, game->img);
	return (0);
}

int	ft_img_switch(int x, int y, t_so_long *game)
{
	ft_img_sprite_4(game->p_x, game->p_y, "0.XPM", game);
	game->p_x += x;
	game->p_y += y;
	if (game->anim_count > 0 && game->anim_count <= 2 * game->delay)
		ft_img_sprite_5(game->p_x, game->p_y, "./H/P1.XPM", game);
	if (game->anim_count > 2 * game->delay && game->anim_count
		<= 4 * game->delay)
		ft_img_sprite_5(game->p_x, game->p_y, "./H/P2.XPM", game);
	if (game->anim_count > 4 * game->delay && game->anim_count
		<= 6 * game->delay)
		ft_img_sprite_5(game->p_x, game->p_y, "./H/P3.XPM", game);
	if (game->anim_count > 6 * game->delay && game->anim_count
		<= 8 * game->delay)
		ft_img_sprite_5(game->p_x, game->p_y, "./H/P4.XPM", game);
	return (0);
}

// int	ft_check_anime_col(t_so_long *game)
// {
// 	if (game->map[game->x_y[game->n_x]][game->x_x[game->n_x]
// 		+ game->x_dx[game->n_x]] == 'C' && game->anim_count == 0)
// 		return (1);
// 	if (game->map[game->x_y[game->n_x]][game->x_x[game->n_x]
// 		+ game->x_dx[game->n_x]] == '1' && game->anim_count == 0)
// 		return (1);
// 	return (0);
// }

int	ft_img_sprite_6(int x, int y, char *xpm, t_so_long *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, xpm,
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, game->div * y);
	mlx_destroy_image(game->mlx, game->img);
	return (0);
}

int	ft_animation(int z, char *P, char *Z, t_so_long *game)
{
	if (game->move_p == 0)
	{
		game->n_x = 0;
		while (game->n_x < game->x)
		{
			if (game->x_dx[game->n_x] != 0)
			{
				ft_img_sprite_4(game->x_x[game->n_x] + game->x_dx[game->n_x],
					game->x_y[game->n_x], "0.XPM", game);
				ft_img_sprite_4(game->x_x[game->n_x], game->x_y[game->n_x],
					"0.XPM", game);
			}
			game->n_x++;
		}
		game->n_x = 0;
		while (game->n_x < game->x)
		{
			ft_img_sprite_6(game->div * game->x_x[game->n_x] + game->div4
				* z * game->x_dx[game->n_x], game->x_y[game->n_x], Z, game);
			if (game->anim_count == 6 * game->delay)
			{
				game->x_x[game->n_x] += game->x_dx[game->n_x];
				game->x_y[game->n_x] += game->x_dy[game->n_x];
			}
			game->n_x++;
		}
		ft_img_sprite_5(game->p_x, game->p_y, P, game);
	}
	return (0);
}

int	ft_death_anim(char *xpm, t_so_long *game)
{
	if (game->move_p < 5 && game->move_p != 0)
	{
		ft_img_sprite_5(game->p_x, game->p_y, xpm, game);
			game->move_p++;
	}
	return (0);
}
