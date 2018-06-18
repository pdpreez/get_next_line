/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:01:58 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/28 10:30:48 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	t_uchar		*dst2;
	t_uchar		*src2;

	i = 0;
	dst2 = (t_uchar *)dst;
	src2 = (t_uchar *)src;
	if (src2 < dst2)
	{
		while (len > i)
		{
			len--;
			dst2[len] = src2[len];
		}
		return (dst2);
	}
	else
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	return (dst);
}
