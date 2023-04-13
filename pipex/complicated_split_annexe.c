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

char	**shortcut(char *src, char **dst, char c, int count) //pipex.h !
{
	int	j;

	j = 0;
	while (*src && *src != c)
		dst[count][j++] = *src++;
	dst[count++][j] = '\0';
	return (dst);
}

char	**ft_fill_big_table(char *src, char c, char **dst, int *lens)
{
//	int	j;
	int	count;
	char	**res;

	count = 0;
	while (*src)
	{
		if (*src == c)
			src++;
		dst[count] = malloc(sizeof(char) * lens[count]);
		if (dst[count] == NULL)
			return (ft_free_split(dst, count));
		free(lens); //
		if (*src == 39)
		{
			src++;
		//	j = 0;
		//	while (*src != 39)
		//		dst[count][j++] = *src++;
		//	dst[count++][j] = '\0';
			res = shortcut(src, dst, 39, count);
			break ;
		}
		else
		{
			//j = 0;
			//while (*src && *src != c)
			//	dst[count][j++] = *src++;
			//dst[count++][j] = '\0';
			res = shortcut(src, dst, c, index);
		}
	}
	dst[count] = NULL;
	return (res);
}
