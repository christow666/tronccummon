/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:52:06 by cperron           #+#    #+#             */
/*   Updated: 2022/11/07 19:47:13 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	ch;

	i = 0;
	if (!s)
		return (NULL);
	ch = (char)c;
	str = (char *)s;
	while (i <= ft_strlen(str))
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
