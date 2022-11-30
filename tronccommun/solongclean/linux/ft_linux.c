// int	key_hook(int keycode, t_so_long *game)
// {
// 	printf("Hello from key_hook! ---> %d\n", keycode);
// 	if (keycode == 65307)
// 		ft_exit_game(game);
// 	if (keycode == 32)
// 		ft_duck(game);
// 	if (keycode == 100 && game->move_p == 0)
// 		ft_move(1, 0, game);
// 	if (keycode == 97 && game->move_p == 0)
// 		ft_move(-1, 0, game);
// 	if (keycode == 115 && game->move_p == 0)
// 		ft_move(0, 1, game);
// 	if (keycode == 119 && game->move_p == 0)
// 		ft_move(0, -1, game);
// 	return (0);
// }
// int	ft_loop(t_so_long *game)
// {
// 	if (game->anim_count == 0)
// 	{
// 		ft_animation("./H/P1.xpm", "./Z/Z1.xpm", game);
// 		ft_enemy_ai(game);
// 	}
// 	if (game->anim_count == 10000)
// 		ft_animation("./H/P2.xpm", "./Z/Z2.xpm", game);
// 	if (game->anim_count == 20000)
// 		ft_animation("./H/P3.xpm", "./Z/Z3.xpm", game);
// 	if (game->anim_count == 30000)
// 		ft_animation("./H/P4.xpm", "./Z/Z4.xpm", game);
// 	game->anim_count++;
// 	if (game->anim_count == 40000)
// 		game->anim_count = 0;
// 	return (0);
// }
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