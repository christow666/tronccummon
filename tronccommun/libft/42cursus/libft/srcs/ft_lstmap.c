/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:16:36 by cperron           #+#    #+#             */
/*   Updated: 2022/11/04 14:55:10 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;

	if (!lst)
		return (NULL);
	nlst = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&nlst, ft_lstnew(f(lst->content)));
		if (!ft_lstlast(nlst))
		{
			ft_lstclear(&nlst, *del);
			return (nlst);
		}
		lst = lst->next;
	}
	return (nlst);
}
