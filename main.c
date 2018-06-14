/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 09:05:47 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/14 10:54:51 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	char **line;
	int gnlret;

	gnlret = 1;
	printf("Argc: %d\n", argc);
	printf("File to open: %s\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	printf("File descriptor: %d\n", fd);
	line = ft_memalloc(sizeof(char **));
	printf("BUFF_SIZE: %d\n", BUFF_SIZE);
	while (gnlret != 0)
	{
		gnlret = get_next_line(fd, &(*line)); 
		printf("Line to print: %s\n", *line);
		printf("gnlret = **%d**\n\n", gnlret);
	}
	printf("Finished\n");
	close(fd);
	return (0);
}	
