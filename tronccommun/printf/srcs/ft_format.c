/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:26:56 by cperron           #+#    #+#             */
/*   Updated: 2022/11/09 15:39:21 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pourcen(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	else
	{
		if (n < 0)
		{
			n = -n;
			i++;
		}
		if (n >= 10)
		{
			i += ft_nbrlen(n / 10);
			i += ft_nbrlen(n % 10);
		}
		else
			i++;
	}
	return (i);
}

int	ft_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_base10(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}

/*int main()
{
	char *s;

	s = "Mussum Ipsum,  per gatis num morreus";
	printf("%d", ft_str(s));
}*/