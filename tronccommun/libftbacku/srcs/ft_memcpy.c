/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:36:26 by cperron           #+#    #+#             */
/*   Updated: 2022/10/24 23:17:03 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*ddst;
	unsigned char	*ssrc;

	i = 0;
	ddst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		ddst[i] = ssrc[i];
		i++;
		n--;
	}
	return (dst);
}
