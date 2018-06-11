/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/11 18:19:41 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		assign(const int fd, char **line, t_list *node, char *buffer)
{
	int	i;
	char *str;

	i = 0;
	str = (char *)node->content;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		if (!(read(fd, buffer, BUFF_SIZE)))
			return (0);
		node->content = ft_strjoin(node->content, buffer);
		assign(fd, line, node, buffer);
	}
	else if (str[i] == '\n')
	{
		*line = ft_strnew(i);
		ft_strncpy(*line, node->content, i);
		node->content = ft_strdup(node->content + (i + 1));
		return (1);
	}
	return (-123);
}

int		readlist(const int fd, char **line, t_list **node, char *buffer)
{
	if (!(*node))
	{
		printf("ft_lstnew call\n");
		if (!(read(fd, buffer, BUFF_SIZE)))
			return (0);
		(*node) = ft_lstnew(buffer, BUFF_SIZE);
		(*node)->content_size = fd;
		printf("Buffer :%s\n", buffer);
	}
	else
	{
		printf("traversal\n");
		while ((*node)->content_size != fd && (*node)->next != NULL)
			node = &(*node)->next;
	}
	printf("Node content: %s\n", (*node)->content);
	if ((*node)->content_size == fd)
	{
		printf("Assign call\n");
		return (assign(fd, line, (*node), buffer));
	}
	return (-312);
}
		
int	get_next_line(const int fd, char **line)
{
	int				read_val;
	char			buffer[BUFF_SIZE + 1];
	static t_list	*node = NULL;

	printf("function call\n");
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	read_val = readlist(fd, line, &node, buffer);
	printf("Almost done reading\n");
	return (read_val);
}
