/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:35:52 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/27 16:36:11 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strcat(char *dst, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*dst;

	if (s1 == 0 || s2 == 0)
		return (0);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	return (dst);
}
