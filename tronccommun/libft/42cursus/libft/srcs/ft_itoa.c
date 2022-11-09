/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:27:18 by christo           #+#    #+#             */
/*   Updated: 2022/11/07 15:42:33 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static int	ft_nlen(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoacore(char *str, int len, int n, int i)
{
	while (0 < len)
	{
		if (n < 0)
		{
			str[i] = '-';
			i++;
			len--;
			n = -n;
		}
		if (n < 10)
			str[i] = n + 48;
		if (n == 0)
			str[i] = 48;
		else
		{
			str[i] = (n / (ft_recursive_power(10, len - 1))) + 48;
			n = n % (ft_recursive_power(10, len - 1));
		}
		len--;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_nlen(n);
	if (n == -2147483648)
	{
		str = ft_calloc(ft_nlen(n) + 1, sizeof(char));
		if (!str)
			return (NULL);
		return (ft_memcpy(str, "-2147483648", 11));
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (ft_itoacore(str, len, n, i));
}
