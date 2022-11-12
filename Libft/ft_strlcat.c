/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:58:59 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/12 14:24:27 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	j = 0;
	if (dstlen < dstsize - 1 && dstsize > 0)
	{
		while (src[j] && dstlen + j < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (dstsize <= dstlen) //dstsize is max. dstlen can't exceed the max. if it exceeds, I return srclen + dstsize
		return (srclen + dstsize);
	return (dstlen + srclen);
}

/*
the strlcpy() and strlcat() functions return the total
length of the string they tried to create. For strlcat() that means 
the initial length of dst plus the length of src.
*/
