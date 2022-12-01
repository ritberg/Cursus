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
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (0);
		s++;
	}
	return (s);
}

// returns the rest of lines (after the first read line)
static char	*the_rest(char *str_save)
{
	size_t	i;
	size_t	ind;
	char	*rest;

	i = 0;
	while (str_save[i] && ft_strchr(str_save, '\n'))
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(str_save) - i + 1)); //size of str_save - i (the fisrt line)
	if (rest == NULL)
		return (NULL);
	ind = 0;
	while (str_save[i])
		rest[ind++] = str_save[i++];
	rest[ind] = '\0';
	return (rest);
}

// read and return the line before \n, \n included
static char	*div_lines(char *str_save)
{
	size_t	i;
	char	*line;

	i = 0;
	while (str_save[i] && ft_strchr(str_save, '\n')) //count i till \n
		i++;
	line = malloc(sizeof(char) * (i + 2)); //malloc for the line str_save[i]
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str_save[i] != '\n')
	{
		line[i] = str_save[i]; //put str_save[i] into line
		i++;
	}
//	line[i] = '\n'; // line[i] to add \n ???
	line[i] = '\0'; // line[i + 1] to add \0 ???
	return (line);
}

// read the file fd and save all the lines in str_save
static char	*read_save(int fd, char *str_save)
{
	char	*temp;
	size_t	read_bytes;

	read_bytes = 1;  // 1 char 1 byte, so start counting from 1 for '\0'
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	while (read_bytes != 0 && ft_strchr(str_save, '\n')) // read_bytes = 0 means EOF
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
//	printf("%s\n", temp);
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
	str_save = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (str_save == NULL)
		return (NULL);
	str_save = read_save(fd, str_save); //read all the file, all lines. save as str_save
//	printf("%s\n", str_save);
	line = div_lines(str_save); //get only 1 line tiil the first \n
//	printf("%s\n", line);
	str_save = the_rest(str_save);
//	printf("%s\n", str_save);
	return (line);
}
