/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:35:57 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/31 09:44:16 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	t_uchar	*dst;

	i = 0;
	dst = (t_uchar *)s;
	while (i < n)
	{
		if (dst[i] == (t_uchar)c)
			return (dst + i);
		i++;
	}
	return (NULL);
}
