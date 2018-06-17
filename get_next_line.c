/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/17 14:18:57 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		assign(const int fd, char **line, t_list **node, char *buffer)
{
	int	i;
	char *str;

	i = 0;
	str = (char *)(*node)->content;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		if (i == 0)
			*line = ft_strdup("");
		else
			*line = ft_strndup((*node)->content, i);
		(*node)->content = (*node)->content + (i + 1);
		return (1);
	}
	ft_bzero(buffer, BUFF_SIZE + 1);
	if (str[i] == '\0')
	{
		if (!(read(fd, buffer, BUFF_SIZE)))
		{
			if (i == 0)
				return (0);
			else
			{
				*line = ft_strdup((*node)->content);
				ft_strclr(str);
				return (1);
			}
		}
		(*node)->content = ft_strjoin((*node)->content, buffer);
		assign(fd, line, node, buffer);
	}
	return (1);
}

int		readinglist(const int fd, char **line, t_list **node, char *buffer)
{
	int	read_val;

	if (!(*node))
	{
		read_val = read(fd, buffer, BUFF_SIZE);
		if (read_val <= 0)
			return (read_val);
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
		return (assign(fd, line, node, buffer));
	}
	return (-1);
}
		
int	get_next_line(const int fd, char **line)
{
	int				read_val;
	char			buffer[BUFF_SIZE + 1];
	static t_list	*node = NULL;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	read_val = readinglist(fd, line, &node, buffer);
	return (read_val);
}
