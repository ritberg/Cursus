/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:57:27 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/02 11:54:05 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// memmove doesn't overlap

/* 
char src[30] = "012345678";
char *dst = src + 4;
memmove(dst, src, 6);
print dst
output 012345
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*destin;
	char	*source;
	char	temp[len];
	size_t	i;

	i = 0;
	source = (char *)src;
	destin = dst;
	while (source[i] && i < len) //try without source[i]
	{
		temp[i] = source[i];
		i++;
	}
	temp[i] = '\0'; // try to remove
	i = 0;
	while (temp[i]) //try i < len
	{
		destin[i] = temp[i];
		i++;
	}
//	destin[i] = '\0';
	return (destin);
}

/*
	int	i;
	char	*destin;
	const char	*source;

	i = 0;
	destin = dst;
	source = src;
	while (source[i] && i < len - 1)
		i++;
	while (i >= 0)
	{
		destin[i] = source[i];
		i--;
	}
	return (destin);
*/
