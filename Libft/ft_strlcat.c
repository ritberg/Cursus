/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:58:59 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/07 16:47:21 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	dstlen = i;
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dstlen) //dstsize is max. dstlen can't exceed the max. if it exceeds, I return srclen + dstsize
		return (srclen + dstsize);
	while (src[j] && i < dstsize - dstlen- 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
