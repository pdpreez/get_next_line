/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:03:04 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/12 16:11:38 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	conv(const char *str, int i, int m)
{
	long	a;
	int		dig;

	a = 0;
	dig = 0;
	while (ft_isdigit(str[i]))
	{
		a *= 10;
		a += str[i] - '0';
		if (m == 1 && dig > 17)
			return (-1);
		if (m == -1 && dig > 17)
			return (0);
		i++;
		dig++;
	}
	return (a);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		m;
	int		a;

	i = 0;
	m = 1;
	if (ft_strlen(str) == 0 || !str)
		return (0);
	while (ft_isspace(str[i]) || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i - 1] == '0')
			return (0);
		if (str[i] == '-')
		{
			m = -1;
		}
		i++;
	}
	a = conv(str, i, m) * m;
	return (a);
}
