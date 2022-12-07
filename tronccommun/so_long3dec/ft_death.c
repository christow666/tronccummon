/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:24:49 by christo           #+#    #+#             */
/*   Updated: 2022/12/06 22:01:37 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_duck(t_so_long *game)
{
	game->img = mlx_new_image(game->mlx, 1000, 1000);
	game->img = mlx_xpm_file_to_image(game->mlx, "d.XPM", &game->img_width,
			&game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	ft_open_exit(t_so_long *game)
{
	ft_xpm_to_img("EO.XPM", game);
	ft_img_to_win(game->e_x, game->e_y, game);
	game->map[game->e_y][game->e_x] = 'e';
	return (0);
}

int	ft_exit_game(t_so_long *game)
{
	printf("Your move ---> %d\n", game->move_count);
	printf("coins remaining ---> %d\n", game->coin_count);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	ft_game_over(t_so_long *game)
{
	if (game->move_p == 0)
	{
		game->move_p = 1;
		ft_duck(game);
	}
	return (0);
}

int	ft_death(t_so_long *game)
{
	game->n_x = 0;
	while (game->n_x < game->x)
	{
		if (game->x_y[game->n_x] == game->p_y && game->x_x[game->n_x]
			== game->p_x)
			ft_game_over(game);
		game->n_x++;
	}
	return (0);
}
