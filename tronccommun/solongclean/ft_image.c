/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:43:00 by christo           #+#    #+#             */
/*   Updated: 2022/11/29 13:44:55 by christo          ###   ########.fr       */
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

int	ft_img_sprite(int x, int y, char *xpm, t_so_long *game)
{
	ft_xpm_to_img(xpm, game);
	ft_img_to_win(x, y, game);
	return (0);
}

int	ft_img_switch(int x, int y, t_so_long *game)
{
	ft_img_sprite(game->p_x, game->p_y, "0.XPM", game);
	game->p_x += x;
	game->p_y += y;
	if (game->anim_count > 0 && game->anim_count <= 10000)
		ft_img_sprite(game->p_x, game->p_y, "./H/P1.xpm", game);
	if (game->anim_count > 10000 && game->anim_count <= 2000)
		ft_img_sprite(game->p_x, game->p_y, "./H/P2.xpm", game);
	if (game->anim_count > 20000 && game->anim_count <= 30000)
		ft_img_sprite(game->p_x, game->p_y, "./H/P3.xpm", game);
	if (game->anim_count > 30000 && game->anim_count <= 40000)
		ft_img_sprite(game->p_x, game->p_y, "./H/P4.xpm", game);
	return (0);
}
