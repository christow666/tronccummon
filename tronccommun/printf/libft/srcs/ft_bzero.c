/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:58:42 by cperron           #+#    #+#             */
/*   Updated: 2022/11/07 15:40:02 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
