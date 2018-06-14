/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/14 16:30:54 by ppreez           ###   ########.fr       */
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
	printf("str: %s\n", str);
//	printf("buffer: %s\n", buffer);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ft_bzero(buffer, BUFF_SIZE + 1);
	if (str[i] == '\0')
	{
		if (!(read(fd, buffer, BUFF_SIZE)))
		{
		//	printf("Final return\n");
			return (0);
		}
		node->content = ft_strjoin(node->content, buffer);
//		printf("Node content: %s\n", node->content);
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
	//printf("Buffer: %s\n", buffer);
	printf("Content: %s\n", node->content);
	if (!ft_strlen(buffer))
		*line = ft_strdup(node->content);
	printf("string i: |%d|\n", i);
	//printf("char i	: |%c|\n", str[i]);
	return (1);
}

int		readlist(const int fd, char **line, t_list **node, char *buffer)
{
	int	read_val;
	if (!(*node))
	{
		//printf("lstnew call\n");
		if (!(read_val = read(fd, buffer, BUFF_SIZE)))
			return (0);

		//printf("Read val: |%d|\n", read_val);
	//	printf("Buffer = |%s|\n", buffer);
		//printf("Last char = |%c|\n", buffer[BUFF_SIZE + 1]);
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
