/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 07:25:52 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/06 17:47:51 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	copy(char **line, char *buffer, char *hold)
{
	int	i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (buffer[i] == '\n')
			ft_strncpy(*line, buffer, i);
		i++;
	}
}

int	get_next_line(const int fd, char **line)
{
	int			read_val;
	char		buffer[BUFF_SIZE];
	static char	*hold;

	printf("Function call\n");
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-2);
	read_val = read(fd, buffer, BUFF_SIZE);
	if (read_val <= 0)
		return (-3);
	if (!(*line = (char *)ft_memalloc(sizeof(char *) * BUFF_SIZE + 1)))
		return (-4);
	copy(line, buffer, hold);
	printf("read_val: **%d**\n", read_val);
	return (read_val);
}
