/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 10:44:12 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/08 16:11:16 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if (!(s2 = (char *)ft_memalloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
