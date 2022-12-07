/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coin_ogro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:58:08 by cperron           #+#    #+#             */
/*   Updated: 2022/12/06 21:58:48 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_coin(int x, int y, t_so_long *game)
{
	game->coin_count--;
	game->map[game->p_y + y][game->p_x + x] = '0';
	game->c_n = 0;
	while (game->c_n < game->c_nn)
	{
		if (game->c_x[game->c_n] == game->p_x + x && game->c_y[game->c_n]
			== game->p_y + y)
		{
			game->c_i[game->c_n] = 1;
			break ;
		}
		game->c_n++;
	}
	if (game->coin_count == 0)
		ft_open_exit(game);
	return (0);
}

int	ft_enemy_col_2(int x, int y, t_so_long *game)
{
	int	i;

	i = 0;
	while (i < game->x)
	{
		if (game->b_x[game->b_n] + x == game->x_x[i]
			&& game->b_y[game->b_n] + y == game->x_y[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_rock(int x, int y, t_so_long *game)
{
	int	i;

	i = 0;
	while (i < game->b_max)
	{
		if (game->b_x[game->b_n] + x == game->b_x[i] && game->b_y[game->b_n] + y
			== game->b_y[i])
			return (1);
		i++;
	}
	if (game->map[game->b_y[game->b_n] + y][game->b_x[game->b_n] + x] != '0'
		&& game->map[game->b_y[game->b_n] + y][game->b_x[game->b_n] + x] != 'O')
		return (1);
	if (ft_enemy_col_2(x, y, game) == 1)
		return (1);
	ft_img_sprite_2(game->b_x[game->b_n], game->b_y[game->b_n],
		0, "0.XPM", game);
	game->map[game->p_y + y][game->p_x + x] = '0';
	game->b_x[game->b_n] += x;
	game->b_y[game->b_n] += y;
	ft_img_sprite_2(game->b_x[game->b_n], game->b_y[game->b_n],
		0, "B.XPM", game);
	return (0);
}

int	ft_ogro_kill(int x, int y, t_so_long *game)
{
	int	i;

	i = 0;
	while (i < game->o_n)
	{
		if (game->o_x[i] == game->p_x && game->o_y[i] == game->p_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_ogro_eat(int x, int y, t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->o_n)
	{
		while (j < game->b_max)
		{
			if (game->o_x[i] == game->b_x[j] && game->o_y[i] == game->b_y[j])
			{
				game->map[game->o_y[i]][game->o_x[i]] = '0';
				ft_img_sprite_2(game->o_x[i], game->o_y[i], 0, "0.XPM", game);
				game->o_x[i] += x;
				game->o_y[i] += y;
				game->b_x[j] = 0;
				game->b_y[j] = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
