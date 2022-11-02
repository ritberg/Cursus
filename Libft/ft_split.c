/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:57:39 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/02 19:24:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_n_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c) // count how many words there are: from one delimiter to an other
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	*ft_malloc_n_words(int count) // malloc for n words
{
	int	j;
	int	*size;

	j = 0;
	size = malloc(sizeof(int*) * ft_n_words(src, c));
	if (size == 0)
		return (0);
	while (j < count)
	{
		size[j] = j;
		j++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	*src;
	char	**dst;
	int	i;
	int	j;

	src = (char *)s;
	dst = malloc(sizeof(char *) * ft_malloc_n_words(count) + 1);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != c)
		{
			while (src[i] && src[i] != c)
			{
				dst[i][j] = src[i];
				i++;
				j++;
			}
		}
		else
			i++;
	}
	return (dst);
}
