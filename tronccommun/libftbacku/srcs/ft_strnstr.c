/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:19:56 by cperron           #+#    #+#             */
/*   Updated: 2022/10/22 19:38:10 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (needle[i] == 0)
		return (h);
	if (haystack[i])
		(void)haystack[i];
	while (&h[i] != 0 && i + ft_strlen(n) <= len)
	{
		if (haystack[i] == 0)
			return (NULL);
		if (ft_strncmp(&h[i], n, ft_strlen(n)) == 0)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
