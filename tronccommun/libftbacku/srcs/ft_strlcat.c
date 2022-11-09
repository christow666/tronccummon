/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:37:34 by cperron           #+#    #+#             */
/*   Updated: 2022/10/21 17:01:14 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	j;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	j = d_len;
	i = 0;
	if (dstsize != 0 && d_len < dstsize - 1)
	{
		while (src[i] != 0)
		{
			dst[j] = src[i];
			j++;
			i++;
			if (j == dstsize - 1)
				break ;
		}
	dst[j] = 0;
	}
	if (d_len < dstsize)
		dstsize = d_len;
	return (dstsize + s_len);
}
