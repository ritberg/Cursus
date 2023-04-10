/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:28:28 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/10 18:36:24 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_n_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	*ft_len_strs(char *str, char c, int n_words)
{
	int	index;
	int	len;
	int	*len_strs;

	len_strs = malloc(sizeof(int) * n_words);
	if (len_strs == 0)
		return (0);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (*str && *str != c)
			{
				str++;
				len++;
			}
			len_strs[index++] = len + 1;
		}
		else
			str++;
	}
	return (len_strs);
}

static char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
	int	j;
	int	count;

	count = 0;
	while (*src)
	{
		if (*src != c)
		{
			dst[count] = malloc(sizeof(char) * lens[count]);
			if (dst[count] == NULL)
				return (NULL);
			j = 0;
			while (*src && *src != c)
				dst[count][j++] = *src++;
			dst[count++][j] = '\0';
		}
		else
			src++;
	}
	dst[count] = NULL;
	return (dst);
}

char	**split_one(char const *s, char c)
{
	char	*src;
	char	**dst;
	int		*lens;
	int		count;

	src = (char *)s;
	count = ft_n_words(src, c);
	lens = ft_len_strs(src, c, count);
	dst = malloc(sizeof(char *) * count);
	if (dst == NULL)
		return (NULL);
	return (ft_fill_big_table(src, c, dst, lens));
}
