/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/15 17:59:36 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		assign(const int fd, char **line, t_list *node, char *buffer, size_t read_val)
{
	int	i;
	char *str;

	i = 0;
	str = (char *)node->content;
//	printf("str: %s\n", str);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
//		printf("str newline\n");
//		printf("Before join: %s\n", node->content);
		*line = ft_strnew(i);
		ft_strncpy(*line, node->content, i);
		node->content = ft_strjoin(node->content + (i + 1), buffer);
//		printf("After join: %s\n", node->content);
		return (1);
	}
	if (str[i] == '\0')
	{
//		printf("str null\n");
		if (!(read(fd, buffer, BUFF_SIZE)))
		{
			*line = ft_strnew(i);
			ft_strncpy(*line, node->content, i);
//			printf("Final return\n");
			return (0);
		}
//		printf("buffer contents: %s\n", node->content);
		printf("Node content: %s\n", node->content);
//		printf("read_val: %zu\n", read_val);
		node->content = ft_strjoin(node->content, buffer);
		assign(fd, line, node, buffer, read_val);
	}
//	printf("assign end\n");
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
		//printf("Buffer = |%s|\n", buffer);
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
		return (assign(fd, line, (*node), buffer, read_val));
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
	//printf("Function call\n");
	ft_bzero(buffer, BUFF_SIZE + 1);
	read_val = readlist(fd, line, &node, buffer);
	//printf("Done with function call\n");
	//printf("Last read_val : %d\n", read_val);
	return (read_val);
}
