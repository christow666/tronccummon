
// int	ft_img_switch_x(int x, int y, t_so_long *game)
// {
// 	ft_xpm_to_img("0.XPM", game);
// 	ft_img_to_win(game->x_x[game->n_x], game->x_y[game->n_x], game);
// 	game->x_x[game->n_x] += x;
// 	game->x_y[game->n_x] += y;
// 	if (game->x_ai[game->n_x] == 1)
// 	{
// 		// ft_xpm_to_img("./Z/Z1.XPM", game);
// 		if (game->anim_count > 0 && game->anim_count <= 10000)
// 			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
// 				"./Z/Z1.xpm", game);
// 		if (game->anim_count > 10000 && game->anim_count <= 20000)
// 			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
// 				"./Z/Z2.xpm", game);
// 		if (game->anim_count > 20000 && game->anim_count <= 30000)
// 			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
// 				"./Z/Z3.xpm", game);
// 		if (game->anim_count > 30000 && game->anim_count <= 40000)
// 			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x],
// 				"./Z/Z4.xpm", game);
// 	}
// 		// ft_img_to_win(game->x_x[game->n_x], game->x_y[game->n_x], game);
// 	if (game->x_ai[game->n_x] == 2)
// 	{
// 		ft_xpm_to_img("X.XPM", game);
// 		ft_img_to_win(game->x_x[game->n_x], game->x_y[game->n_x], game);
// 	}
// 	return (0);
// }

	// if (keycode == 65307)
	// 	ft_exit_game(game);
	// if (keycode == 32)
	// {
	// 	game->move_p = 1;
	// 	ft_duck(game);
	// }
	// if (keycode == 114)
	// 	game->move_p = 0;
	// if (keycode == 100 && game->move_p == 0)
	// 	ft_move(1, 0, game);
	// if (keycode == 97 && game->move_p == 0)
	// 	ft_move(-1, 0, game);
	// if (keycode == 115 && game->move_p == 0)
	// 	ft_move(0, 1, game);
	// if (keycode == 119 && game->move_p == 0)
		// ft_move(0, -1, game);
			// if (keycode == 65363 && game->move_p == 0)
	// 	ft_move(1, 0, game);
	// if (keycode == 65361 && game->move_p == 0)
	// 	ft_move(-1, 0, game);
	// if (keycode == 65364 && game->move_p == 0)
	// 	ft_move(0, 1, game);
	// if (keycode == 65362 && game->move_p == 0)
	// 	ft_move(0, -1, game);

			// if (game->map[y][x] == 'X')
			// {
			// 	game->x_x[game->n_x] = x;
			// 	game->x_y[game->n_x] = y;
			// 	game->x_ai[game->n_x] = 2;
			// 	game->x_dx[game->n_x] = 1;
			// 	game->x_dy[game->n_x] = 0;
			// 	ft_xpm_to_img("X.XPM", game);
			// 	game->n_x++;
			// 	game->x++;
			// }

// int ft_bat_move(t_so_long *game)
// {
// 	game->n_x = 0;
// 	while (game->n_x < game->x)
// 	{	
// 		game->x_x[game->n_x] += game->x_dx[game->n_x];
// 		game->x_y[game->n_x] += game->x_dy[game->n_x];
// 		game->n_x++;
// 	}
// 	return (0);
// }