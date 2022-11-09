/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:38:38 by cperron           #+#    #+#             */
/*   Updated: 2022/11/07 15:17:10 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static	int	ft_nbplit(const char *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

static	char	**ft_splitcore(const char *s, char c, char **tab)
{
	int	i;
	int	ii;

	i = 0;
	ii = -1;
	while (++ii < ft_nbplit(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (ft_strchr(&s[i], c))
		{
			tab[ii] = ft_substr(&s[i], 0, (ft_strchr(&s[i], c) - &s[i]));
			if (!tab[ii])
				return (ft_free(tab));
			i += (ft_strchr(&s[i], c) - &s[i]);
		}
		else
		{
			tab[ii] = ft_substr(&s[i], 0, ft_strlen(&s[i]));
			if (!tab[ii])
				return (ft_free(tab));
			i += ft_strlen(&s[i]);
		}
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc(sizeof(char *), (ft_nbplit(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_splitcore(s, c, tab));
}
