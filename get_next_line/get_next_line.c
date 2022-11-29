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


/*
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*read_save(int fd, char *str_save)
{
	char	*temp;
	int	read_bytes;

	//read_bytes = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	while (!ft_strchr(temp, '\n') && read_bytes != 0) // read_bytes = 0 means EOF
	{
		read_bytes = read(fd, temp, BUFFER_SIZE); // read function returns n of read bytes
		if (read_bytes == - 1) // -1 is retured if there is an error
		{
			free(temp);
			return (NULL);
		}
		temp[read_bytes] = '\0';
		str_save = ft_strjoin(str_save, temp);
	}
	free(temp);
	return (str_save);
}
// how the iteration is done in the while above????

char	*get_next_line(int fd)
{
	static char	*str_save;
	int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_str = read_save(fd, str_save);
	if (save_str == NULL)
		return (NULL);
	return ();
}
