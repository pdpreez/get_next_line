/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:03:50 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/16 13:28:04 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	dstlen;

	j = 0;
	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (ft_strlen(src) + dstsize);
	while (src[j] && dstlen + j < dstsize - 1)
	{
		dst[dstlen + j] = src[j];
		j++;
	}
	dst[dstlen + j] = '\0';
	return (dstlen + ft_strlen(src));
}
