/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:25:43 by ppreez            #+#    #+#             */
/*   Updated: 2018/06/07 17:33:41 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		buffline(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\n' && i <= BUFF_SIZE)
		i++;
	return (i);
}

void	assign(const int fd, char **line, t_list *node, char *buffer)
{
	char *tmp;

	if (node->content == NULL)
		tmp = ft_strdup(buffer);
	else 


void	readlist(const int fd, char **line, t_list *node, char *buffer)
{

	if (node == NULL)
	{
		node = (t_list)ft_memalloc(sizeof(t_list));
		node->content = NULL;
		node->content_size = NULL;
		node->next = NULL;
	}
	while (node->content_size != fd && node->next != NULL)
		node = node->next;
	if (node->content_size == fd)
		assign(fd, &line, node, buffer);
	else if (node->content_size != fd && node->next == NULL)
		ft_lstadd(buffer, fd);



		
int	get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE];
	static t_list	*node = NULL;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while (read(fd, buffer, BUFF_SIZE) == BUFF_SIZE)
	{
		readlist(fd, &line, node, buffer);
