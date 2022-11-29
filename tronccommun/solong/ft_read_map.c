/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:19:46 by christo           #+#    #+#             */
/*   Updated: 2022/11/29 06:28:11 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_img_to_map(int x, int y, t_so_long *game)
{
	int	n;

	n = 0;
	game->win = mlx_new_window(game->mlx, game->div * 19,
			game->div * 25, "so_long");
	game->img = mlx_new_image(game->mlx, game->div * 10, game->div * 19);
	while (x < 19)
	{
		while (y < 10)
		{
			if (game->map[y][x] == '1')
				ft_xpm_to_img("1.XPM", game);
			if (game->map[y][x] == 'E')
			{
				game->e_x = x;
				game->e_y = y;
				ft_xpm_to_img("E.XPM", game);
			}
			if (game->map[y][x] == 'X')
			{
				game->x_x[game->n_x] = x;
				game->x_y[game->n_x] = y;
				game->x_ai[game->n_x] = 2;
				game->x_dx[game->n_x] = 1;
				game->x_dy[game->n_x] = 0;
				ft_xpm_to_img("X.XPM", game);
				game->n_x++;
				game->x++;
			}
			if (game->map[y][x] == 'Z')
			{
				game->x_x[game->n_x] = x;
				game->x_y[game->n_x] = y;
				game->x_ai[game->n_x] = 1;
				game->x_dx[game->n_x] = 1;
				game->x_dy[game->n_x] = 0;
				ft_xpm_to_img("Z.XPM", game);
				game->n_x++;
				game->x++;
			}
			if (game->map[y][x] == 'C')
			{
				ft_xpm_to_img("C.XPM", game);
				game->coin_count++;
			}
			if (game->map[y][x] == '0')
				ft_xpm_to_img("0.XPM", game);
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				ft_xpm_to_img("P.XPM", game);
			}
			ft_img_to_win(x, y, game);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int	ft_print_map(int x, int y, t_so_long *game)
{
	while (y < 10)
	{
		while (x < 19)
		{
			printf("%c", game->map[y][x]);
			x++;
		}
		x = 0;
		printf("%c", '\n');
		y++;
	}
	return (0);
}

int	ft_map_init(t_so_long *game, char str[200])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_print_map(x, y, game);
	ft_img_to_map(x, y, game);
	ft_xpm_to_img("0.XPM", game);
	return (0);
}

int	ft_write_map(int fd, char str[200], t_so_long *game)
{
	int		x;
	int		y;
	int		k;

	k = 0;
	x = 0;
	y = 0;
	while (k < 200 && str[k])
	{
		game->map[y][x] = str[k];
		k++;
		x++;
		if (str[k] == '\n')
		{
			y++;
			k++;
			x = 0;
		}
	}
	ft_map_init(game, str);
	return (0);
}

int	ft_read_map(t_so_long *game)
{
	char	str[200];
	int		fd;

	fd = open("2.ber", O_RDONLY);
	read(fd, str, 200);
	// printf("%s", str);
	close(fd);
	ft_write_map(fd, str, game);
	return (0);
}
