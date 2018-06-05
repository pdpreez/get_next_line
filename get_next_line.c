/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 07:25:52 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/05 14:08:48 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int			i;
	int			read_val;
	static char	*buffer[BUFF_SIZE];

	i = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	while ((read_val = read(fd, buffer, BUFF_SIZE) != 0))
	{
		if (read_val < 0)
			return (-1);
		while (buffer[i] != '\n' && buffer[i] && i < BUFF_SIZE)
		{
