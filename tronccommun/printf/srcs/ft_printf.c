/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:14 by cperron           #+#    #+#             */
/*   Updated: 2022/11/09 15:27:07 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_checkformat(va_list args, const char format)
{
	if (format == 'c')
		return (ft_char(va_arg(args, int)));
	if (format == 's')
		return (ft_str(va_arg(args, char *)));
	if (format == 'i' || format == 'd')
		return (ft_base10(va_arg(args, int)));
	if (format == '%')
		return (ft_pourcen());
	if (format == 'u')
		return (ft_unsint(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int)));
	if (format == 'X')
		return (ft_putnbr_hexx(va_arg(args, unsigned int)));
	if (format == 'p')
		return (ft_pointer(va_arg(args, unsigned long long)));
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
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		if (format[i] == '%')
		{
			count += ft_checkformat(args, format[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	printf("%d\n", printf("%s\n", "waispouper"));
	printf("%d\n", ft_printf("%s\n", "waispouper"));
	return (0);
}*/
