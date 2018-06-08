/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/08 17:04:36 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	assign(const int fd, char **line, t_list *node, char *buffer)
{
	size_t	i;

	i = 0;
	if (node->content == NULL)
	{
		node->content = (char *)ft_memalloc(sizeof(char *) * ft_linelen(buffer, BUFF_SIZE));
		while (i < ft_linelen(buffer, BUFF_SIZE))
		{
			node->content = ft_strdup(buffer);
			i++;
		}
	}
	else
	{
		i = ft_linelen(buffer, BUFF_SIZE);
	}
}




void	readlist(const int fd, char **line, t_list *node, char *buffer)
{
	printf("Node create\n");
	if (node == NULL)
	{
		printf("ft_lstnew call\n");
		node = ft_lstnew(buffer, ft_strlen(buffer));
	}
	printf("Node traverse\n");
	while (node->content_size != fd && node->next != NULL)
	{
		printf("traversal in loop\n");
		node = node->next;
	}
	printf("assign\n");
	if (node->content_size == fd)
		assign(fd, line, node, buffer);
	//else if (node->content_size != fd && node->next == NULL)
}



		
int	get_next_line(const int fd, char **line)
{
	int				read_val;
	char			buffer[BUFF_SIZE];
	static t_list	*node = NULL;

	printf("function call\n");
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((read_val = read(fd, buffer, BUFF_SIZE)) == BUFF_SIZE)
	{
		printf("readlist\n");
		readlist(fd, line, node, buffer);
	}
	if (read_val < BUFF_SIZE)
		printf("Almost done reading\n");
	return (444);
}
