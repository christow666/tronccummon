/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:19:46 by christo           #+#    #+#             */
/*   Updated: 2022/12/06 22:18:49 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

int	ft_map_init(t_so_long *game)
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

int	ft_write_map(char str[200], t_so_long *game)
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
	ft_map_init(game);
	return (0);
}

int	ft_read_map(t_so_long *game)
{
	char	str[201];
	int		fd;

	str[200] = '\0';
	fd = open("2.ber", O_RDONLY);
	read(fd, str, 200);
	close(fd);
	ft_write_map(str, game);
	return (0);
}
