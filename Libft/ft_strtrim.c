/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:48:42 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/31 18:18:42 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 1; // because the first and last characters are not copied
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	char	*str2;
	char	*str1;
	int	len;
	int	i;
	int	j;

	str1 = (char *)s1;
	len = ft_strlen(str1);
	while (set[i])
	{
		if (str1[0] != set[i])
			*str2 = ft_strcpy(str1);
		i++;
	}
	
}
