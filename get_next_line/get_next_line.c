/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:34:35 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/29 10:57:59 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (s);
}

static char	*read_save(int fd, char *str_save)
{
	char	*temp;
	int	read_bytes;

	read_bytes = 1;  // 1 char 1 byte, so start counting from 1 for '\0'
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	while (!ft_strchr(temp, '\n') && read_bytes != 0) // read_bytes = 0 means EOF
	{
		read_bytes = read(fd, temp, BUFFER_SIZE); // read function returns n of read bytes
		if (read_bytes == -1) // -1 is retured if there is an error
		{
			free(temp);
			return (NULL);
		}
		temp[read_bytes] = '\0'; //I've read the line from fd and put in temp
								 //here I add a '\0' 
								 //temp[read_bytes] not read_bytes - 1
								 //because read_bytes initialized from 1
		str_save = ft_strjoin(str_save, temp);
	}
	free(temp);
	return (str_save);
}

char	*get_next_line(int fd)
{
	static char	*str_save;
	int	i;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_save = read_save(fd, str_save);
	if (str_save == NULL)
		return (NULL);
	return (str_save);
}
