/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:58 by cperron           #+#    #+#             */
/*   Updated: 2022/11/09 15:39:11 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_pointer(unsigned long long n)
{
	int	i;

	i = 2;
	write(1, "0x", 2);
	i += ft_putnbr_hex(n);
	return (i);
}

int	ft_putnbr_hexx(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_hexx(n / 16);
		i += ft_putnbr_hexx(n % 16);
	}
	else
	{
		write(1, &"0123456789ABCDEF"[n % 16], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_hex(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_hex(n / 16);
		i += ft_putnbr_hex(n % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[n % 16], 1);
		i++;
	}
	return (i);
}

int	ft_unsint(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_unsint(n / 10);
		i += ft_unsint(n % 10);
	}
	else
	{
		write(1, &"0123456789"[n % 10], 1);
		i++;
	}
	return (i);
}
