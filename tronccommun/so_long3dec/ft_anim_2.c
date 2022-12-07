/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:31:22 by cperron           #+#    #+#             */
/*   Updated: 2022/12/06 23:31:36 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_coin_anim_2(char *xpm, t_so_long *game)
{
	if (game->c_i[game->c_n] > 0 && game->c_i[game->c_n] < 8)
	{
		ft_img_sprite_3(0, 0, "0.XPM", game);
		if (game->map[game->c_y[game->c_n] - 1][game->c_x[game->c_n]]
			== '1')
			ft_img_sprite_4(game->c_x[game->c_n], game->c_y[game->c_n]
				- 1, "1.XPM", game);
		else
			ft_img_sprite_4(game->c_x[game->c_n], game->c_y[game->c_n]
				- 1, "0.XPM", game);
		ft_img_sprite_3(1, 1 - game->c_i[game->c_n], xpm, game);
		game->c_i[game->c_n]++;
	}
	return (0);
}

int	ft_coin_anim(char *xpm, t_so_long *game)
{
	game->c_n = 0;
	while (game->c_n < game->c_nn)
	{
		if (game->c_i[game->c_n] == 0)
		{
			ft_img_sprite_3(0, 0, "0.XPM", game);
			ft_img_sprite_3(1, 1, xpm, game);
		}
		ft_coin_anim_2(xpm, game);
		if (game->c_i[game->c_n] == 8)
		{
			if (game->map[game->c_y[game->c_n] - 2][game->c_x[game->c_n]]
				== '1')
				ft_img_sprite_4(game->c_x[game->c_n], game->c_y[game->c_n]
					- 2, "1.XPM", game);
			else
				ft_img_sprite_4(game->c_x[game->c_n], game->c_y[game->c_n]
					- 2, "0.XPM", game);
			game->c_i[game->c_n]++;
		}
		game->c_n++;
	}
	return (0);
}

int	ft_bat_kill(int x, t_so_long *game)
{
	if (game->move_p == 0)
	{
		game->n_x = 0;
		while (game->n_x < game->x)
		{
			if (game->x_y[game->n_x] == game->p_y && game->x_x[game->n_x] + x
				* game->x_dx[game->n_x]
				== game->p_x)
				ft_game_over(game);
			game->n_x++;
		}
	}
	return (0);
}

int	ft_orgro_anim(char *O, t_so_long *game)
{
	int	i;

	i = 0;
	while (i < game->o_n)
	{
		ft_img_sprite_2(game->o_x[i], game->o_y[i], 0, O, game);
		i++;
	}
	return (0);
}