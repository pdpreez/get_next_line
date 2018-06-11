/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/11 14:18:05 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	assign(const int fd, char **line, t_list *node, char *buffer)
{
	int	i;
	char *str;

	i = 0;
	str = (char *)node->content;
	while (str[i] != '\n')
		i++;

	*line = ft_strnew(i);
	ft_strncpy(*line, node->content, i);
	printf("*line: %s\n", *line);
	node->content = ft_strdup(node->content + (i + 1));
}




void	readlist(const int fd, char **line, t_list **node, char *buffer)
{
	printf("Node create\n");
	if ((*node))
		read(fd, buffer, BUFF_SIZE);
	if (!(*node))
	{
		printf("ft_lstnew call\n");
		read(fd, buffer, BUFF_SIZE);
		(*node) = ft_lstnew(buffer, BUFF_SIZE);
		(*node)->content_size = fd;
	}
	printf("fd: %d\n", fd);
	printf("Node content: \n%s\n", (*node)->content);
	if ((*node)->content_size == fd)
	{
		printf("Assign call\n");
		assign(fd, line, (*node), buffer);
	}
	//else if (node->content_size != fd && node->next == NULL)
}



		
int	get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*node = NULL;

	printf("function call\n");
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	ft_strclr(buffer);
	readlist(fd, line, &node, buffer);
	printf("Almost done reading\n");
	return (1);
}
