/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tft_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:37:34 by cperron           #+#    #+#             */
/*   Updated: 2022/10/20 19:34:21 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	offset;
	size_t	src_index;
	int		i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	offset = d_len;
	src_index = 0;
	if (dstsize != 0 && d_len < dstsize)
	{
		while (src[src_index] != 0)
		{
			dst[offset] = src[src_index];
			offset++;
			src_index++;
			if (offset == dstsize - 1)
				break ;
		}
		dst[offset] = 0;
	}
	i = 0;
	while (dst[i])
	{
		write(1, &dst[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (d_len + s_len);
}

int	main(int ac, char **av)
{
	int	c;

	(void)av;
	c = 15;
	if (ac != 0)
		printf("%zu", ft_strlcat(av[1], av[2], c));
	return (0);
}