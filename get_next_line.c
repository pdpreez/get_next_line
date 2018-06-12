/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/12 17:41:44 by ppreez           ###   ########.fr       */
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
	//printf("str: %s\n", str);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		if (!(read(fd, buffer, BUFF_SIZE)))
		{
		//	printf("Final return\n");
			return (0);
		}
		node->content = ft_strjoin(node->content, buffer);
		assign(fd, line, node, buffer);
	}
	else if (str[i] == '\n')
	{
		*line = ft_strnew(i);
		ft_strncpy(*line, node->content, i);
		node->content = ft_strdup(node->content + (i + 1));
		//printf("Newline return\n");
		return (1);
	}
	return (1);
}

int		readlist(const int fd, char **line, t_list **node, char *buffer)
{
	if (!(*node))
	{
		if (!(read(fd, buffer, BUFF_SIZE)))
			return (0);
		(*node) = ft_lstnew(buffer, BUFF_SIZE + 1);
		(*node)->content_size = fd;
	}
	else
	{
		while ((*node)->content_size != (size_t)fd && (*node)->next != NULL)
			node = &(*node)->next;
	}
	if ((*node)->content_size == (size_t)fd)
	{
		return (assign(fd, line, (*node), buffer));
	}
	return (-312);
}
		
int	get_next_line(const int fd, char **line)
{
	int				read_val;
	char			buffer[BUFF_SIZE + 1];
	static t_list	*node = NULL;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	read_val = readlist(fd, line, &node, buffer);
	return (read_val);
}
