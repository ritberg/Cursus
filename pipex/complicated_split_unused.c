/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complicated_split_unused.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:47:16 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/20 14:35:34 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile.txt "grep -e 'a cat' -e 'k'" "wc -w" outfile.txt

char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
	int	j;
	int	count;

	count = 0;
	while (*src)
	{
		dst[count] = malloc(sizeof(char) * lens[count]);
		if (dst[count] == NULL)
			return (ft_free_split(dst, count));
		j = 0;
		if (*src == '\'' && src++)
			while (*src != '\'')
				dst[count][j++] = *src++;
		else
			while (*src && *src != c)
				dst[count][j++] = *src++;
		dst[count++][j] = '\0';
		if (*src == '\'')
			src++;
		if (*src == c)
			src++;

		/*
		if (*src == '\'')
		{
			src++;
			j = 0;
			while (*src != '\'')
				dst[count][j++] = *src++;
			dst[count++][j] = '\0';
			break ;
		}
		else
		{
			j = 0;
			while (*src && *src != c)
				dst[count][j++] = *src++;
			dst[count++][j] = '\0';
		}
		*/
	}
	dst[count] = NULL;
	free(lens);
	return (dst);
}
