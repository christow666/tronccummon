/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:21:31 by christo           #+#    #+#             */
/*   Updated: 2022/11/29 06:37:00 by cperron          ###   ########.fr       */
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

int	ft_img_sprite(int x, int y, char *xpm, t_so_long *game)
{
	ft_xpm_to_img(xpm, game);
	ft_img_to_win(x, y, game);
	return (0);
}

int	ft_img_switch(int x, int y, t_so_long *game)
{
	ft_xpm_to_img("0.XPM", game);
	ft_img_to_win(game->p_x, game->p_y, game);
	game->p_x += x;
	game->p_y += y;
	if (game->anim_count > 0 && game->anim_count <= 1500)
		ft_img_sprite(game->p_x, game->p_y, "./H/P1.XPM", game);
	if (game->anim_count > 1500 && game->anim_count <= 3000)
		ft_img_sprite(game->p_x, game->p_y, "./H/P2.XPM", game);
	if (game->anim_count > 3000 && game->anim_count <= 4500)
		ft_img_sprite(game->p_x, game->p_y, "./H/P3.XPM", game);
	if (game->anim_count > 4500 && game->anim_count <= 6000)
		ft_img_sprite(game->p_x, game->p_y, "./H/P4.XPM", game);
	// ft_xpm_to_img("P.XPM", game);
	// ft_img_to_win(game->p_x, game->p_y, game);
	return (0);
}

int	ft_move(int x, int y, t_so_long *game)
{
	if (game->map[game->p_y + y][game->p_x + x] == '1'
			|| game->map[game->p_y + y][game->p_x + x] == 'E')
		return (1);
	if (game->map[game->p_y + y][game->p_x + x] == 'C')
	{
		game->coin_count--;
		game->map[game->p_y + y][game->p_x + x] = '0';
		if (game->coin_count == 0)
			ft_open_exit(game);
	}
	ft_img_switch(x, y, game);
	game->move_count++;
	game->n_x = 0;
	while (game->n_x < game->x)
	{
		if (game->x_y[game->n_x] == game->p_y && game->x_x[game->n_x] == game->p_x)
		{
			game->move_p = 1;
			ft_duck(game);
		}
		game->n_x++;
	}
	// ft_enemy_ai(game);
	if (game->map[game->p_y][game->p_x] == 'e')
	{
		printf("Your move ---> %d\n", game->move_count);
		printf("coins remaining ---> %d\n", game->coin_count);
		mlx_destroy_window(game->mlx, game->win);
		// mlx_loop_end(game->mlx);
		exit(0);
	}
	return (0);
}

int	key_hook(int keycode, t_so_long *game)                           
{
	printf("Hello from key_hook! ---> %d\n", keycode);
	if (keycode == 53)
	{
		printf("Your move ---> %d\n", game->move_count);
		printf("coins remaining ---> %d\n", game->coin_count);
		mlx_destroy_window(game->mlx, game->win);
		// mlx_loop_end(game->mlx);
		exit(0);
	}
	if (keycode == 32)
		ft_duck(game);
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


// int	ft_img_sprite(int x, int y, char *xpm, t_so_long *game)
// {
// 	ft_xpm_to_img(xpm, game);
// 	ft_img_to_win(x, y, game);
// 	return (0);
// }

int ft_hobbit_dance(t_so_long *game)
{
	if (game->anim_count == 0)
	{
		ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
		ft_img_sprite(game->p_x, game->p_y, "./H/P1.XPM", game);
	}
	if (game->anim_count == 1500)
	{
		ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
		ft_img_sprite(game->p_x, game->p_y, "./H/P2.XPM", game);
	}
	if (game->anim_count == 3000)
	{
		ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
		ft_img_sprite(game->p_x, game->p_y, "./H/P3.XPM", game);
	}
	if (game->anim_count == 4500)
	{
		ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
		ft_img_sprite(game->p_x, game->p_y, "./H/P4.XPM", game);
	}
	if (game->anim_count == 6000)
		game->anim_count = 0;
	game->anim_count++;
	return(0);
}

int ft_bat_dance(t_so_long *game)
{
	if (game->anim_count == 1)
	{
		game->n_x = 0;
		while (game->n_x < game->x)
		{
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "0.XPM", game);
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "./Z/Z1.XPM", game);
			game->n_x++;
		}
	}
	if (game->anim_count == 1500)
	{
		game->n_x = 0;
		while (game->n_x < game->x)
		{
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "0.XPM", game);
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "./Z/Z2.XPM", game);
			game->n_x++;
		}
	}
	if (game->anim_count == 3000)
	{
		game->n_x = 0;
		while (game->n_x < game->x)
		{
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "0.XPM", game);
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "./Z/Z3.XPM", game);
		game->n_x++;
		}
	}
	if (game->anim_count == 4500)
	{
		game->n_x = 0;
		while (game->n_x < game->x)
		{
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "0.XPM", game);
			ft_img_sprite(game->x_x[game->n_x], game->x_y[game->n_x], "./Z/Z4.XPM", game);
		game->n_x++;
		}
	}
	// if (game->anim_count == 6000)
	// 	game->anim_count = 0;
	// game->anim_count++;
	return(0);
}

int ft_loop(t_so_long *game)
{
	ft_hobbit_dance(game);
	ft_bat_dance(game);
	if (game->anim_count == 20)
		ft_enemy_ai(game);
	return (0);
}

int	main(void)
{
	t_so_long	game;

	game.mlx = mlx_init();
	game.div = 100;
	game.anim_count = 0;
	game.move_count = 0;
	game.coin_count = 0;
	game.n_x = 0;
	game.x = 0;
	game.move_p = 0;
	ft_read_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop_hook(game.mlx, ft_loop, &game);
	mlx_loop(game.mlx);
	// printf("Your move ---> %d\n", game.move_count);
	return (0);
}
