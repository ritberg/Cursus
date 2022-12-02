/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:34:35 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/29 10:57:59 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// returns the rest of lines (after the first read line)

static void	the_rest(char *str_save)
{
	size_t	i;
	size_t	ind;

	i = 0;
	ind = 0;
	while (str_save[i] && str_save[i] != '\n')
		i++;
	i++;
	while (str_save[i])
		str_save[ind++] = str_save[i++];
	str_save[ind] = '\0';
}

// read and return the line before \n, \n included
static char	*div_lines(char *all_strs)
{
	size_t	i;
	char	*line;

	if (all_strs == NULL)
		return (NULL);
	i = 0;
	while (all_strs[i] && all_strs[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (all_strs[i] && all_strs[i] != '\n')
	{
		line[i] = all_strs[i];
		i++;
	}
	if (all_strs[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	read_save_additional(int read_bytes, char **temp, char *str_save)
{
	char	*tmp_free;

	if (read_bytes == -1)
	{
		free(*temp);
		return (0);
	}
	str_save[read_bytes] = '\0';
	tmp_free = ft_strjoin(*temp, str_save);
	free(*temp);
	*temp = tmp_free;
	if (*temp == NULL)
		return (0);
	return (1);
}

// read the file fd and save all the lines in str_save
static char	*read_save(int fd, char *str_save)
{
	char	*temp;
	int		read_bytes;
	int		i;

	read_bytes = 1;
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	temp = ft_strcpy(temp, str_save);
	while (read_bytes != 0 && ft_strchr(str_save, '\n'))
	{
		i = 0;
		while(i <= BUFFER_SIZE)
			str_save[i++] = '\0';
		read_bytes = read(fd, str_save, BUFFER_SIZE);
		if (!read_save_additional(read_bytes, &temp, str_save))
		   return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	str_save[1024][BUFFER_SIZE + 1];
	char	*line;
	char	*all_strs;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_strs = read_save(fd, str_save[fd]);
	if (all_strs == NULL)
		return (NULL);
	line = div_lines(all_strs); 
	free(all_strs);
	if (line == NULL)
		return (NULL);
	the_rest(str_save[fd]);
	if (ft_strlen(line)) 
		return (line);
	free(line);
	return (NULL);
}
