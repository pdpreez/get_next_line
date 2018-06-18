/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:17:46 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/18 14:44:59 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(str) || !n)
		return (NULL);
	new = (char *)ft_memalloc(n + 1);
	while (i < n)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
