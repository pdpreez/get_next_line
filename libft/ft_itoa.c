/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:18:25 by ppreez            #+#    #+#             */
/*   Updated: 2018/05/30 08:39:46 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*assign(char *s, int count, int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		s[0] = '-';
		i++;
		n *= -1;
	}
	while (count >= i)
	{
		s[count] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	int		len;
	int		count;
	char	*arr;

	len = n;
	count = 0;
	if (n == MININT)
		return (ft_strdup(MININTSTR));
	if (n < 0)
		count++;
	if (n == 0)
	{
		arr = ft_strnew(1);
		arr[0] = '0';
		return (arr);
	}
	while (len > 9 || len < -9)
	{
		len /= 10;
		count++;
	}
	if (!(arr = ft_strnew(count + 1)))
		return (NULL);
	return (assign(arr, count, n));
}
