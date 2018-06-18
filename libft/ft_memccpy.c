/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:29:34 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/29 14:30:26 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	t_uchar		*dst2;
	t_uchar		*src2;

	i = 0;
	dst2 = (t_uchar *)dst;
	src2 = (t_uchar *)src;
	if (!(src || dst))
		return (NULL);
	while (i < n)
	{
		dst2[i] = src2[i];
		if (dst2[i] == (t_uchar)c)
			return (dst2 + i + 1);
		i++;
	}
	return (NULL);
}
