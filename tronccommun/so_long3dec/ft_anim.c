/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:26:57 by cperron           #+#    #+#             */
/*   Updated: 2022/12/07 23:16:12 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_check_rock_col(t_so_long *game)
{
	game->b_n = 0;
	while (game->b_n < game->b_max)
	{
		if (game->x_x[game->n_x] + game->x_dx[game->n_x] == game->b_x[game->b_n]
			&& game->x_y[game->n_x] == game->b_y[game->b_n])
			return (1);
		game->b_n++;
	}
	return (0);
}

int	ft_if_bat(t_so_long *game)
{
	if (game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]]
		[game->x_x[game->n_x] + game->x_dx[game->n_x]] == '1'
		|| game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]]
		[game->x_x[game->n_x] + game->x_dx[game->n_x]] == 'E'
		|| game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]]
		[game->x_x[game->n_x] + game->x_dx[game->n_x]] == 'C'
		|| game->map[game->x_y[game->n_x] + game->x_dy[game->n_x]]
		[game->x_x[game->n_x] + game->x_dx[game->n_x]] == 'e'
		|| ft_check_rock_col(game) == 1)
		return (1);
	return (0);
}

int	ft_bat_checkmove(t_so_long *game)
{
	game->n_x = 0;
	while (game->n_x < game->x)
	{
		if (ft_if_bat(game) == 1)
		{
			game->x_dx[game->n_x] *= -1;
			if (ft_if_bat(game) == 1)
			game->x_dx[game->n_x] = 0;
		}
		game->n_x++;
	}
	return (0);
}

int	ft_img_sprite_5(int x, int y, char *xpm, t_so_long *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "0.XPM",
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->div * x, game->div * y);
	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_xpm_file_to_image(game->mlx, xpm,
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->div * x, game->div * y);
	mlx_destroy_image(game->mlx, game->img);
	return (0);
}
int	ft_img_sprite_4(int x, int y, char *xpm, t_so_long *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, xpm,
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->div * x, game->div * y);
	mlx_destroy_image(game->mlx, game->img);
	return (0);
}

int	ft_img_sprite_3(int dx, int dy, char *xpm, t_so_long *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, xpm,
			&game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->div * game->c_x[game->c_n] + game->div4 * dx, game->div
		* game->c_y[game->c_n] + game->div4 * dy);
	mlx_destroy_image(game->mlx, game->img);
	return (0);
}
