/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:04:16 by cperron           #+#    #+#             */
/*   Updated: 2022/11/09 15:27:41 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_char(int c);
int	ft_str(char *s);
int	ft_base10(int n);
int	ft_pourcen(void);
int	ft_decimal(double n);
int	ft_unsint(unsigned int n);
int	ft_putnbr_hex(unsigned long long n);
int	ft_putnbr_hexx(unsigned int n);
int	ft_pointer(unsigned long long n);

#endif