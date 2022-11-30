/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:53:23 by christo           #+#    #+#             */
/*   Updated: 2022/11/30 05:30:05 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_img_switch_x(int x, int y, t_so_long *game)
{
	// ft_xpm_to_img("0.XPM", game);
	// ft_img_to_win(game->x_x[game->n_x], game->x_y[game->n_x], game);
	game->x_x[game->n_x] += x;
	game->x_y[game->n_x] += y;
	// if (game->x_ai[game->n_x] == 1)
	// {
	// 	if (game->anim_count >= 0 && game->anim_count <= 1500)
	// 		ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
	// 			"./Z/Z1.xpm", game);
	// 	if (game->anim_count > 1500 && game->anim_count <= 3000)
	// 		ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
	// 			"./Z/Z2.xpm", game);
	// 	if (game->anim_count > 3000 && game->anim_count <= 4500)
	// 		ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
	// 			"./Z/Z3.xpm", game);
	// 	if (game->anim_count > 4500 && game->anim_count <= 6000)
	// 		ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
	// 			"./Z/Z4.xpm", game);
	// }
	if (game->x_ai[game->n_x] == 2)
	{
		ft_xpm_to_img("X.XPM", game);
		ft_img_to_win(game->x_x[game->n_x], game->x_y[game->n_x], game);
	}
	return (0);
}

int	ft_enemy_col(int x, int y, t_so_long *game)
{
	int	i;

	i = 0;
	while (i < game->x)
	{
		if (game->x_x[game->n_x] + x == game->x_x[i] + x
			&& game->x_y[game->n_x] + y == game->x_y[i]
			&& i != game->n_x)
			return (1);
		if (game->x_x[game->n_x] == game->x_x[i]
			&& game->x_y[game->n_x] + y == game->x_y[i]
			&& i != game->n_x)
			return (1);
		i++;
	}
	return (0);
}

int	ft_enemy_move(int x, int y, int d, t_so_long *game)
{
	// if (ft_enemy_col(x, y, game) == 1)
	// 	return (1);
	if (game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x] == '1'
			|| game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x]
				== 'E')
		return (1);
	if (game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x] == 'C'
			|| game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x]
				== 'e')
		return (1);
	ft_img_switch_x(x, y, game);
	if (game->x_y[game->n_x] == game->p_y && game->x_x[game->n_x] == game->p_x)
	{
		game->move_p = 1;
		ft_duck(game);
	}
	return (0);
}

int	ft_enemy_ai_1(t_so_long *game)
{
	if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
			0, game) == 1)
	{
		game->x_dx[game->n_x] *= -1;
		game->x_dy[game->n_x] = 0;
		ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x], 0, game);
	}
	return (0);
}

int	ft_enemy_ai_2(t_so_long *game)
{
	if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
			0, game) == 1)
	{
		if (game->x_dy[game->n_x] == -1)
		{
			game->x_dx[game->n_x] = 1;
			game->x_dy[game->n_x] = 0;
			ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
				0, game);
			return (0);
		}
	game->x_dx[game->n_x] = 0;
	game->x_dy[game->n_x] = 1;
		if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
				1, game) == 1)
		{
		game->x_dx[game->n_x] = -1;
		game->x_dy[game->n_x] = 0;
			if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
					2, game) == 1)
			{
				game->x_dx[game->n_x] = 0;
				game->x_dy[game->n_x] = -1;
			}
		}
	}
	return (0);
}

int	ft_enemy_ai(t_so_long *game)
{
	game->n_x = 0;
	while (game->n_x < game->x)
	{
		if (game->x_ai[game->n_x] == 1)
			ft_enemy_ai_1(game);
		if (game->x_ai[game->n_x] == 2)
			ft_enemy_ai_2(game);
		game->n_x++;
	}
	return (0);
}

