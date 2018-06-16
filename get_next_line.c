/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/16 15:26:57 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		assign(const int fd, char **line, t_list **node, char *buffer, size_t read_val)
{
	int	i;
	char *str;

	i = 0;
	str = (char *)(*node)->content;
//	printf("str: %s\n", str);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
	//	printf("str newline\n");
		*line = ft_strndup((*node)->content, i);
//		printf("Line: %s\n", *line);
	//	printf("Before join: %s\n", str);
		(*node)->content = (*node)->content + (i + 1);
	//	printf("After join: %s\n", str);
		return (1);
	}
	ft_bzero(buffer, BUFF_SIZE + 1);
	if (str[i] == '\0')
	{
	//	printf("str null\n");
		if (!(read(fd, buffer, BUFF_SIZE)))
		{
		//			printf("Final return\n");
			if (i == 0)
			{
				*line = ft_strdup("");
				return (0);
			}
			else
			{
				*line = ft_strndup((*node)->content, i);
				ft_strclr(str);
				return (1);
			}
		}
//		printf("buffer contents: %s\n", node->content);
//		printf("Node content: %s\n", (*node)->content);
		(*node)->content = ft_strjoin((*node)->content, buffer);
		assign(fd, line, node, buffer, read_val);
			}
//	printf("assign end\n");
	return (1);
}

int		readinglist(const int fd, char **line, t_list **node, char *buffer)
{
	int	read_val;

	if (!(*node))
	{
//		printf("lstnew call\n");
		read_val = read(fd, buffer, BUFF_SIZE);
			if (read_val <= 0)
				return (read_val);
	//		printf("Buffer = |%s|\n", buffer);
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
		return (assign(fd, line, node, buffer, read_val));
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
	read_val = readinglist(fd, line, &node, buffer);
	//printf("Done with function call\n");
	return (read_val);
}
