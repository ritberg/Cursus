/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complicated_split_annexe.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:47:16 by mmakarov          #+#    #+#             */
/*   Updated: 2023/04/13 18:42:18 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
	int	j;
	int	count;

	count = 0;
	while (*src)
	{
		if (*src == c)
			src++;
		dst[count] = malloc(sizeof(char) * lens[count]);
		if (dst[count] == NULL)
			return (ft_free_split(dst, count));
		if (*src == 39)
		{
			src++;
			j = 0;
			while (*src != 39)
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
	}
	dst[count] = NULL;
	free(lens);
	return (dst);
}
