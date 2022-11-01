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

int	ft_check(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	char	*src;
	int	len;
	int	i;
	int	k;

	if (s1 == 0)
		return (NULL);
	len = ft_strlen(s1);
	src = (char *)s1;
	i = 0;
	while (ft_check(src[i], set)) // remove set characters from left to right
		i++;           //i si e fermato quando sono finiti i caratteri di set
	while (ft_check(src[len - 1], set) && (len - 1) > 0) // remove set characters from right to left. > 0 because src[0] has been already checked in the previous wjile loop
		len--;
	if ((len - i) < 0) //len - size, i - without set characters, len - i is a piece of the source sentence
		len = 0;
	dst = malloc(len - i + 1);
	if (dst == 0)
		return (NULL);
	k = 0;
	while (i < len)
	{
		dst[k] = src[i];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
 Previous tentatives

		if (src[0] != set[i] || src[len - 1] != set[i])
		{
			dst[j] = src[j];
			j++;
		}
		else
		{
			j = 1;
			while (j < len)
			{
				dst[j] = src[j];
				j++;
			}
		}
		i++;
	}
*/
