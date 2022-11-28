/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:34:35 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/28 17:08:46 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*dst;
	char	*src;
	int	len;
	int	i;

	len = 0;
	while (src[len])
		len++;
	dst = malloc(sizeof(*src) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (src == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
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

char	*get_next_line(int fd)
{
	char	str[100];
	int	i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while (str[i] != '\n')
	{
		read(fd, &str[i], 1); 
		i++;
	}
	return (ft_strdup(str));
}
