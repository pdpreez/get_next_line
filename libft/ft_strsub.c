/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:13:32 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/31 16:47:34 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, t_uint start, size_t len)
{
	char *sub;

	if (!s)
		return (NULL);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	ft_strncpy(sub, s + start, len);
	return (sub);
}
