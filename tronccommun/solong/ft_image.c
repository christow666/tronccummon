/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:43:00 by christo           #+#    #+#             */
/*   Updated: 2022/11/29 03:46:08 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_xpm_to_img(char *imgf, t_so_long *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, imgf,
			&game->img_width, &game->img_height);
	return (0);
}

int	ft_img_to_win(int i, int j, t_so_long *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->div * i, game->div * j);
	return (0);
}
