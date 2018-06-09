/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/09 12:21:08 by ppreez           ###   ########.fr       */
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
		printf("If assign\n");
		node->content = (char *)ft_memalloc(sizeof(char *) * ft_linelen(buffer, BUFF_SIZE));
		while (i < ft_linelen(buffer, BUFF_SIZE))
		{
			node->content = ft_strjoin((char *)node->content, buffer);
			i++;
		}
	}
	else
	{
		printf("Else assign\n");
		node->content = ft_strjoin((char *)node->content + ft_linelen(buffer, BUFF_SIZE), buffer);
	}
}




void	readlist(const int fd, char **line, t_list **node, char *buffer)
{
	printf("Node create\n");
	read(fd, buffer, BUFF_SIZE);
	if (!(*node))
	{
		printf("ft_lstnew call\n");
		(*node) = ft_lstnew(buffer, BUFF_SIZE);
		//return ;
	}
	printf("Node traverse\n");
//	printf("Node->content print: %s\n", (*node)->content);
	while ((*node)->content_size != fd && (*node)->next != NULL)
	{
		printf("traversal in loop\n");
		(*node) = (*node)->next;
	}
	(*node)->content_size = fd;
	if ((*node)->content_size == fd)
	{
		printf("Assign call\n");
		*line = ft_strdup((char *)(*node)->content + (ft_linelen((*node)->content, BUFF_SIZE)));
		assign(fd, line, (*node), buffer);
	}
	//else if (node->content_size != fd && node->next == NULL)
}



		
int	get_next_line(const int fd, char **line)
{
	int				read_val;
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
