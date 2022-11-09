/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tooctal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:18:15 by cperron           #+#    #+#             */
/*   Updated: 2022/10/19 16:13:03 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_tooctal(int c)
{
	int	r;
	int	q;

	if (c <= 8)
		return (c);
	if (c >= 8)
	{
		q = c / 8;
		r = c % 8;
		if (c % 8 == 0 && q == 0)
			return (r * 10);
		return (ft_tooctal(q) * 10 + r);
	}
	return (0);
}

/*int	main(int ac, char **av)
{
	int	c;

	c = 6969;
	if (ac != 0)
		printf("%d", ft_tooctal(c));
	return (0);
}*/
