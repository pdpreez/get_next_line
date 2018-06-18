/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:09:52 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/30 08:42:23 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhite(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	revlen;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return ((char *)s);
	revlen = ft_strlen(s);
	while (iswhite(s[index]) && s[index] != '\0')
		index++;
	if (index >= revlen)
		return (ft_strnew(index));
	while (iswhite(s[revlen - 1]))
		revlen--;
	if (!(str = ft_strnew(revlen - index)))
		return (NULL);
	ft_strncpy(str, s + index, revlen - index);
	return (str);
}
