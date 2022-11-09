/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:14 by cperron           #+#    #+#             */
/*   Updated: 2022/11/08 16:02:51 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_char(int c)
{
	write(1, &c, 1);
	return (2);
}

int	ft_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i + 1);
}

char	ft_checkformat(va_list args, const char format)
{
	if (format == 'c')
		return (ft_char(va_arg(args, int)));
	if (format == 's')
		return (ft_str(va_arg(args, char *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_checkformat(args, format[i + 1]);
			i += 2;
		}
		if (format[i] == 10)
			write(1, "\n", 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	printf("%d\n", printf("%s\n", "waispouper"));
	printf("%d\n", ft_printf("%s\n", "waispouper"));
	return (0);
}
