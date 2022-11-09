/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:24:28 by cperron           #+#    #+#             */
/*   Updated: 2022/10/25 19:47:34 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && dstsize - 1 > 0)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
