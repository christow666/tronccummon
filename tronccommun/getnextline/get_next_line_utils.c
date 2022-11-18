/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:36:27 by cperron           #+#    #+#             */
/*   Updated: 2022/11/17 18:47:17 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_check_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ss;
	int				i;

	i = 0;
	if (!s)
		return ;
	ss = (unsigned char *)s;
	while (n > 0)
	{
		ss[i] = 0;
		i++;
		n--;
	}	
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*str;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_trim(char *str, char *st)
{
	char	*trim;
	int		i;
	int		j;

	i = 0;
	j = 0;
	trim = ft_calloc (sizeof(char), ft_strlen(str) - ft_strlen(st) + 2);
	if (!trim)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			while (str[i])
			{
				trim[j] = str[i + 1];
				j++;
				i++;
			}
		}
		i++;
	}
	free(str);
	return (trim);
}
