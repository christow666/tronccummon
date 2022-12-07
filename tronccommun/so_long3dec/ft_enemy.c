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

// int	ft_enemy_col(int x, int y, t_so_long *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->x)
// 	{
// 		if (game->x_x[game->n_x] + x == game->x_x[i] + x
// 			&& game->x_y[game->n_x] + y == game->x_y[i]
// 			&& i != game->n_x)
// 			return (1);
// 		if (game->x_x[game->n_x] == game->x_x[i]
// 			&& game->x_y[game->n_x] + y == game->x_y[i]
// 			&& i != game->n_x)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_img_switch_x(int x, int y, t_so_long *game)
// {
// 	// ft_xpm_to_img("0.XPM", game);
// 	// ft_img_to_win(game->x_x[game->n_x], game->x_y[game->n_x], game);
// 	game->x_x[game->n_x] += x;
// 	game->x_y[game->n_x] += y;
// 	if (game->x_ai[game->n_x] == 2)
// 	{
// 		ft_xpm_to_img("X.XPM", game);
// 		ft_img_to_win(game->x_x[game->n_x], game->x_y[game->n_x], game);
// 	}
// 	return (0);
// }



// int	ft_enemy_ai_2(t_so_long *game)
// {
// 	if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
// 			0, game) == 1)
// 	{
// 		if (game->x_dy[game->n_x] == -1)
// 		{
// 			game->x_dx[game->n_x] = 1;
// 			game->x_dy[game->n_x] = 0;
// 			ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
// 				0, game);
// 			return (0);
// 		}
// 	game->x_dx[game->n_x] = 0;
// 	game->x_dy[game->n_x] = 1;
// 		if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
// 				1, game) == 1)
// 		{
// 		game->x_dx[game->n_x] = -1;
// 		game->x_dy[game->n_x] = 0;
// 			if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
// 					2, game) == 1)
// 			{
// 				game->x_dx[game->n_x] = 0;
// 				game->x_dy[game->n_x] = -1;
// 			}
// 		}
// 	}
// 	return (0);
// }

// int	ft_enemy_ai(t_so_long *game)
// {
// 	game->n_x = 0;
// 	while (game->n_x < game->x)
// 	{
// 		if (game->x_ai[game->n_x] == 1)
// 			ft_enemy_ai_1(game);
// 		if (game->x_ai[game->n_x] == 2)
// 			ft_enemy_ai_2(game);
// 		game->n_x++;
// 	}
// 	return (0);
// }

