/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/17 17:46:03 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoinfree(void *s1, char const *s2)
{
	char *temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	s1 = temp;
	return (s1);
}

static int		assign(const int fd, char **line, t_list *node, char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)node->content;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		if (i > 0)
		{
			free(*line);
			*line = ft_strndup(node->content, i);
		}
		node->content = node->content + (i + 1);
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
				free(*line);
				*line = ft_strdup(node->content);
				ft_strclr(str);
				return (1);
			}
		}
		node->content = ft_strjoinfree(node->content, buffer);
		assign(fd, line, node, buffer);
	}
	return (1);
}

static t_list	*read_list(const int fd, t_list *node)
{
	if (!node)
	{
		node = ft_lstnew(0, 0);
		node->content_size = fd;
	}
	while (node->content_size != (size_t)fd && node->next != NULL)
		node = node->next;
	if (node->content_size != (size_t)fd && node->next == NULL)
		ft_lstadd(&node, ft_lstnew(0, 0));
	return (node);
}

int				get_next_line(const int fd, char **line)
{
	int				read_val;
	char			buffer[BUFF_SIZE + 1];
	static t_list	*node = NULL;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	ft_bzero(buffer, BUFF_SIZE + 1);
	node = read_list(fd, node);
	if (node->content == NULL)
	{
		read_val = read(fd, buffer, BUFF_SIZE);
		if (read_val <= 0)
			return (read_val);
		if (!(node->content = (void*)ft_memalloc(BUFF_SIZE + 1)))
			return (-1);
		ft_memcpy(node->content, buffer, BUFF_SIZE);
		node->content_size = fd;
	}
	read_val = assign(fd, line, node, buffer);
	return (read_val);
}
