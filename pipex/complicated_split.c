/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complicated_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:47:31 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/18 20:51:54 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_n_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (*str == '\'' && str++)
			{
				count++;
				while (*str && *str != '\'')
					str++;
				str++;
			}
			else
			{
				count++;
				while (*str && *str != c)
					str++;
			}
		}
		else
			str++;
	}
	return (count);
}

/*
int	ft_n_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (*str == 39)
			{
				count++;
				break ;
			}
			else
			{
				count++;
				while (*str && *str != c)
					str++;
			}
		}
		else
			str++;
	}
	return (count);
}
*/

int	*ft_len_strs(char *str, char c, int count, int index)
{
	int	*len_strs;
	int	len;

	len_strs = malloc(sizeof(int) * count);
	if (len_strs == 0)
		return (0);
	while (*str)
	{
		len = 0;
		if (*str == c)
			str++;
		while (*str && *str != c)
		{
			if (*str == '\'' && str++)
			{
				while (*str != '\'')
				{
					len++;
					str++;
				}
			}
			else
			{
				str++;
				len++;
			}
		}
		len_strs[index++] = len + 1;
	}
	return (len_strs);
}

/*
int	*ft_len_strs(char *str, char c, int count, int index)
{
	int	*len_strs;
	int	len;

	len_strs = malloc(sizeof(int) * count);
	if (len_strs == 0)
		return (0);
	while (*str)
	{
		if (*str == c)
			str++;
		len = 0;
		if (*str == 39)
			str++;
		while (*str && *str != c)
		{
			str++;
			len++;
			if (*str == 39)
				break ;
		}
		len_strs[index++] = len + 1;
	}
	return (len_strs);
}
*/

char	**ft_free_split(char **dst, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
		free(dst[k++]);
	free(dst);
	return (NULL);
}

char	**ft_splitpath(char *s, char c)
{
	char	**dst;
	int		*lens;
	int		count;
	int		index;

	index = 0;
	count = ft_n_words(s, c);
	printf("%d\n", count);
	lens = ft_len_strs(s, c, count, index);
	dst = malloc(sizeof(char *) * (count + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_fill_big_table(s, c, dst, lens));
}
