/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:56:54 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/29 17:44:15 by mmakarov         ###   ########.fr       */
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
	int i;
	char	*destin;
	const char	*source;

	destin = dst;
	source = src;
	i = 0;
	while (source[i] && i < n)
	{
		destin[i] = source[i];
		i++;
	}
	destin[i] = '\0';
	return (destin);
}
