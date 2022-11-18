/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:53:06 by cperron           #+#    #+#             */
/*   Updated: 2022/11/17 18:48:36 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *buffer)
{
	char		*result;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !buffer)
		return (NULL);
	if ((ft_strlen(s1) + ft_strlen(buffer)) == 0)
		return (free (s1), NULL);
	result = ft_calloc((ft_strlen(s1) + ft_strlen(buffer) + 2), sizeof(char));
	if (!result)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	while (buffer[j])
	{
		result[i + j] = buffer[j];
		j++;
	}
	free (s1);
	return (result);
}

char	*ft_get_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(ft_strlen(stock) + 1, sizeof(char));
	while (1)
	{
		line[i] = stock[i];
		if (line[i] == '\n' || line[i] == '\0')
			break ;
		i++;
	}
	return (line);
}

static char	*ft_read(int fd, char *stock)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = ft_calloc (sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_check_nl(stock) == 1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(stock);
			free(buffer);
			buffer = NULL;
			stock = NULL;
			return (NULL);
		}
		stock = ft_strjoin_gnl(stock, buffer);
		if (i == 0)
			break ;
	}
	return (free(buffer), stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	int			i;

	i = 0;
	if (fd > 10 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!stock)
		stock = ft_calloc (sizeof(char), BUFFER_SIZE + 1);
	stock = ft_read(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_trim(stock, line);
	if (!stock)
	{
		free (stock);
		stock = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("caca", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	//printf("%s", get_next_line(fd));
// 	return (69);
// }
