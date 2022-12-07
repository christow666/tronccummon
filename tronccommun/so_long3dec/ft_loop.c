/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:44:06 by christo           #+#    #+#             */
/*   Updated: 2022/12/06 23:33:05 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_count_6(t_so_long *game)
{
	ft_coin_anim("./C/C4.XPM", game);
	ft_orgro_anim("./O/O4.XPM", game);
	ft_animation(4, "./H/P4.XPM", "./Z/Z4.XPM", game);
	ft_death_anim("./H/PD7.XPM", game);
	ft_bat_kill(0, game);
	return (0);
}

int	ft_count_4(t_so_long *game)
{
	ft_coin_anim("./C/C3.XPM", game);
	ft_orgro_anim("./O/O3.XPM", game);
	ft_death_anim("./H/PD5.XPM", game);
	ft_animation(3, "./H/P3.XPM", "./Z/Z3.XPM", game);
	ft_bat_kill(1, game);
	return (0);
}

int	ft_count_2(t_so_long *game)
{
	ft_coin_anim("./C/C2.XPM", game);
	ft_orgro_anim("./O/O2.XPM", game);
	ft_death_anim("./H/PD3.XPM", game);
	ft_animation(2, "./H/P2.XPM", "./Z/Z2.XPM", game);
	ft_bat_kill(1, game);
	return (0);
}

int	ft_count_0(t_so_long *game)
{
	ft_coin_anim("./C/C1.XPM", game);
	ft_orgro_anim("./O/O1.XPM", game);
	ft_death_anim("./H/PD1.XPM", game);
	ft_bat_checkmove(game);
	ft_animation(1, "./H/P1.XPM", "./Z/Z1.XPM", game);
	ft_bat_kill(0, game);
	return (0);
}

int	ft_loop(t_so_long *game)
{
	if (game->anim_count == 0)
		ft_count_0(game);
	if (game->anim_count == 2 * game->delay)
		ft_count_2(game);
	if (game->anim_count == 4 * game->delay)
		ft_count_4(game);
	if (game->anim_count == 6 * game->delay)
		ft_count_6(game);
	if (game->move_p != 5)
	game->anim_count++;
	if (game->anim_count == 8 * game->delay)
		game->anim_count = 0;
	return (0);
}
