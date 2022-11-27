/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:34:35 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/27 18:13:32 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static lines	*ft_lstnew(void *content)
{
	lines	*new_line;

	new_line = malloc(sizeof(*new_line));
	if (new_line == NULL)
		return (NULL);
	new_line->content = content;
	new_line->next = NULL;
	return (new_line);
}	

int	ft_strlen(char *str)
{
	len = 0;

	while (str[len])
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	static void *buff;

	ft_lstnew(buff);
	read(fd, buff, ft_strlen(buff));
}
