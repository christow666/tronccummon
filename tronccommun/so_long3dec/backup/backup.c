/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:19:52 by christo           #+#    #+#             */
/*   Updated: 2022/11/26 08:09:54 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_mlx_pixel_put(t_so_long *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	make_line_h(t_so_long img, int x)
{
	int	i;

	i = 100;
	while (i <= 400)
	{
		my_mlx_pixel_put(&img, i, x, 0x00FF0000);
		i++;
	}
}

void	make_line_v(t_so_long img, int x)
{
	int	i;

	i = 100;
	while (i <= 400)
	{
		my_mlx_pixel_put(&img, x, i, 0x000CEF39);
		i++;
	}
}

	// game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel,
	// 		&game.line_length, &game.endian);

int	duck_flash(t_so_long *game)
{
	game->anim_count++;
	if (game->anim_count == 1000)
	{
		game->img = mlx_new_image(game->mlx, 1000, 1000);
		game->img = mlx_xpm_file_to_image(game->mlx, "d.XPM", &game->img_width,
				&game->img_height);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	if (game->anim_count == 2000)
	{
		game->anim_count = 0;
		game->img = mlx_xpm_file_to_image(game->mlx, "duck.XPM",
				&game->img_width, &game->img_height);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	}
	return (0);
}

		// printf("p_x : %d\n", game->p_x);
		// printf("p_y : %d\n", game->p_y);
		// printf("map : %c\n", game->map[game->p_x][game->p_y]);
		// printf("map x + 1: %c\n", game->map[game->p_x + 1][game->p_y]);
		// printf("map x - 1: %c\n", game->map[game->p_x - 1][game->p_y]);
		// printf("map bug: %c\n", game->map[3][1]);
		// int	ft_enemy_move(int x, int y, int d, t_so_long *game)
// {
// 	// if (ft_enemy_col(x, y, game) == 1)
// 	// 	return (1);
// 	if (game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x] == '1'
// 			|| game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x]
// 				== 'E')
// 		return (1);
// 	if (game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x] == 'C'
// 			|| game->map[game->x_y[game->n_x] + y][game->x_x[game->n_x] + x]
// 				== 'e')
// 		return (1);
// 	ft_img_switch_x(x, y, game);
// 	if (game->x_y[game->n_x] == game->p_y && game->x_x[game->n_x] == game->p_x)
// 	{
// 		game->move_p = 1;
// 		ft_duck(game);
// 	}
// 	return (0);
// }

// int	ft_enemy_ai_1(t_so_long *game)
// {
// 	if (ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x],
// 			0, game) == 1)
// 	{
// 		game->x_dx[game->n_x] *= -1;
// 		game->x_dy[game->n_x] = 0;
// 		ft_enemy_move(game->x_dx[game->n_x], game->x_dy[game->n_x], 0, game);
// 	}
// 	return (0);
// }