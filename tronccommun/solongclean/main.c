/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:21:31 by christo           #+#    #+#             */
/*   Updated: 2022/11/30 06:55:01 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_coin(int x, int y, t_so_long *game)
{
	game->coin_count--;
	game->map[game->p_y + y][game->p_x + x] = '0';
	if (game->coin_count == 0)
		ft_open_exit(game);
	return (0);
}

int	ft_move(int x, int y, t_so_long *game)
{
	if (game->map[game->p_y + y][game->p_x + x] == '1'
			|| game->map[game->p_y + y][game->p_x + x] == 'E')
		return (1);
	if (game->map[game->p_y + y][game->p_x + x] == 'C')
		ft_coin(x, y, game);
	ft_img_switch(x, y, game);
	game->move_count++;
	ft_death(game);
	game->n_x = 0;
	while (game->n_x < game->x)
	{
		if (game->x_y[game->n_x] == game->p_y && game->x_x[game->n_x]
			== game->p_x)
			ft_game_over(game);
		game->n_x++;
	}
	if (game->map[game->p_y][game->p_x] == 'e')
		ft_exit_game(game);
	return (0);
}

int	key_hook(int keycode, t_so_long *game)
{
	printf("Hello from key_hook! ---> %d\n", keycode);
	if (keycode == 53)
		ft_exit_game(game);
	if (keycode == 49)
	{
		game->move_p = 1;
		ft_duck(game);
	}
	if (keycode == 15)
		game->move_p = 0;
	// if (keycode == 2 && game->move_p == 0)
	// 	ft_move(1, 0, game);
	// if (keycode == 0 && game->move_p == 0)
	// 	ft_move(-1, 0, game);
	// if (keycode == 1 && game->move_p == 0)
	// 	ft_move(0, 1, game);
	// if (keycode == 13 && game->move_p == 0)
	// 	ft_move(0, -1, game);
	return (0);
}

int	ft_run(int keycode, t_so_long *game)
{
	if (keycode == 2 && game->move_p == 0)
		ft_move(1, 0, game);
	if (keycode == 0 && game->move_p == 0)
		ft_move(-1, 0, game);
	if (keycode == 1 && game->move_p == 0)
		ft_move(0, 1, game);
	if (keycode == 13 && game->move_p == 0)
		ft_move(0, -1, game);
	return (0);
}

int	main(void)
{
	t_so_long	game;

	game.mlx = mlx_init();
	game.div = 100;
	game.div4 = 25;
	game.anim_count = 0;
	game.move_count = 0;
	game.coin_count = 0;
	game.n_x = 0;
	game.x = 0;
	game.move_p = 0;
	ft_read_map(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_run, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop_hook(game.mlx, ft_loop, &game);
	mlx_loop(game.mlx);
	printf("Your move ---> %d\n", game.move_count);
	return (0);
}
