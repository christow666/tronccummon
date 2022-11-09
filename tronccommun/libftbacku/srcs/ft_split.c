/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:38:38 by cperron           #+#    #+#             */
/*   Updated: 2022/10/27 17:59:33 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}*/

/*int	ft_checklen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_nbplit(const char *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			nb++;
		i++;
	}
	return (nb + 1);
}

char	**ft_split(const char *s, char c)
{
	int				i;
	int				j;
	int				k;
	char			**strp;

	i = 0;
	j = 0;
	k = 0;
	strp = malloc(sizeof(char*) * (ft_nbplit(s, c) + 1));
	strp[i] = malloc(sizeof(char) * ft_checklen(&s[k], c) + 1);
	while (s[k])
	{
		while (s[k] == c)
		{
			if (s[k + 1] == c)
				break ;
			k++;
			strp[i][j] = 0;
			i++;
			j = 0;
			strp[i] = malloc(sizeof(char) * ft_checklen(&s[k], c) + 1);
		}
		strp[i][j] = s[k];
		j++;
		k++;
	}
	i++;
	j = 0;
	strp[i] = malloc(sizeof(char) * 1);
	strp[i][j] = 0;
	return (strp);
}*/

/*int	main(int ac, char **av)
{
	char **tabstr;
	int i;

	(void)av;

	i = 0;
	if (ac != 0)
	{
	//	printf("%s", ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' '));
	tabstr = ft_split("lorem ipsum   5 8   dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	printf ("%s\n", tabstr[0]);
	printf ("%s\n", tabstr[1]);
	printf ("%s\n", tabstr[2]);
	printf ("%s\n", tabstr[3]);
	printf ("%s\n", tabstr[4]);
	printf ("%s\n", tabstr[5]);
	printf ("%s\n", tabstr[6]);
	printf ("%s\n", tabstr[7]);
	printf ("%s\n", tabstr[8]);
	printf ("%s\n", tabstr[9]);
	printf ("%s\n", tabstr[10]);
	printf ("%s\n", tabstr[11]);
	printf ("%s\n", tabstr[12]);
	printf ("%s\n", tabstr[13]);
	printf ("%s\n", tabstr[14]);
	return (0);
	}
}*/

int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ii;
	int		words;
	char	**tab;

	if (!s)
		return (NULL);
	i = -1;
	words = ft_count(s, c);
	tab = ft_calloc(sizeof(char *), (words + 1));
	if (!tab)
		return (NULL);
	while (++i < words)
	{
		while (*s && *s == c)
			s++;
		if (ft_strchr(s, c))
			ii = ft_strchr(s, c) - s;
		else
			ii = ft_strlen(s);
		tab[i] = ft_substr(s, 0, ii);
		s += ii;
	}
	return (tab);
}