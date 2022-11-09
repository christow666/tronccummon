/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:22:00 by cperron           #+#    #+#             */
/*   Updated: 2022/10/26 17:13:41 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main(int ac, char **av)
{
	int	c;
	//char s[] = "123456";
	char *s;
	int len;

	(void)av;
	c = 48 ;
	s = "123456";
	len = 4;
	if (ac != 0)
		printf("%s", ft_memset(s, c, len));
	return (0);
}
/*
int i;

i = 0;
while("condition")
	printf("%d", str[i]);
	i++:
*/