/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:56:54 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/07 16:07:11 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//memcpy does overlap

/*
char src[60] = "012345678";
char *dst = src + 4;
ft_memcpy(dst, src, 6);
print  dst
output: 012301
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*destin;
	unsigned char	*source;

	destin = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (destin == NULL && source == NULL)
		return (NULL);
	while (source[i] && i < n)
	{
		destin[i] = source[i];
		i++;
	}
	destin[i] = '\0';
	return (destin);
}
