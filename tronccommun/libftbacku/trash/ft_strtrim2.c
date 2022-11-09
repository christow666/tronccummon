/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:38:04 by cperron           #+#    #+#             */
/*   Updated: 2022/11/07 19:38:27 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int	ft_checkset(const char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}*/

/*char	*ft_strtrim(const char *s1, const char *set)
{
	size_t			i;
	size_t			s;
	char			*str;

	i = 0;
	s = 0;
	if (!s1 || !set)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		if (ft_checkset(s1[i], set) == 0)
			break ;
		i++;
	}
	while (s1[i])
	{
		str[s] = s1[i];
		i++;
		s++;
	}
	while (ft_checkset(str[s - 1], set) == 1)
	{
		str[s - 1] = 0;
		s--;
	}
	return (str);
}*/

/*int	main(int ac, char **av)
{
	int	c;
	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char *s;
	int len;

	(void)av;
	c = 48 ;
	s = "12345622213212321";
	len = 4;
	if (ac != 0)
		printf("%s", ft_strtrim(s, "123"));
	return (0);
}*/

	/*if (ft_strncmp(s1, set, ft_strlen(set)) == 0)
	{
		while (i < ft_strlen(s1))
		{
			str[i] = s1[i + ft_strlen(set)];
			i++;
		}
	}
	else
	{
		while (i < ft_strlen(s1))
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (ft_strncmp(&s1[i], &set[i - ft_strlen(s1)], ft_strlen(set)) == 0)
	{
		str[i] = 0;
		return (str);
	}
	else
	{
		while (j < ft_strlen(set))
		{
			str[i] = 0;
			i--;
			j++;
		}
		return (str);
	}*/