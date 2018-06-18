/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:19:06 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/04 14:06:03 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *node;

	if (!(lst))
		return (NULL);
	start = f(lst);
	node = start;
	lst = lst->next;
	while (lst)
	{
		node->next = f(lst);
		node = node->next;
		lst = lst->next;
	}
	return (start);
}
