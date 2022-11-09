/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:58:03 by cperron           #+#    #+#             */
/*   Updated: 2022/11/07 16:09:31 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bb;
	int				i;

	i = 0;
	if (!b)
		return (NULL);
	bb = (unsigned char *)b;
	while (len > 0)
	{
		bb[i] = (unsigned char)c;
		i++;
		len--;
	}
	i = 0;
	return (b);
}
