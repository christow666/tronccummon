/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:41:10 by cperron           #+#    #+#             */
/*   Updated: 2022/10/24 23:12:51 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned char	*s;
	int				a;
	int				p;

	i = 0;
	p = 1;
	a = 0;
	s = (unsigned char *)str;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v'
		|| s[i] == '\n' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			p = p * -1;
		i++;
	}
	while (ft_isdigit(s[i]) != 0)
	{
		a = a * 10 + (s[i] - 48);
		i++;
	}
	return (a * p);
}
