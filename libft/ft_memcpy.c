/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:06:44 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/26 10:58:25 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	t_uchar	*dst2;
	t_uchar	*src2;

	i = 0;
	dst2 = (t_uchar *)dst;
	src2 = (t_uchar *)src;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
