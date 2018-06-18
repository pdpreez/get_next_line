/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:57:45 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/28 14:12:37 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dst;

	i = 0;
	dst = b;
	if (len <= 0)
		return (b);
	while (i < len)
	{
		dst[i] = c;
		i++;
	}
	return (dst);
}
