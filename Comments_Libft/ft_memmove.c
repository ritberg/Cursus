/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:57:27 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/29 13:18:10 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char src[30] = "012345678";
// char *dst = src + 4;
// memmove(dst, src, 6);
// print dst
// output 012345

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;
	char	*destin;
	const char	*source;

	i = 0;
	destin = dst;
	source = src;
	while (source[i] && i < len - 1) //why -1? backslash zero?
		i++;
	while (i >= 0)
	{
		destin[i] = source[i];
		i--;
	}
	destin[i] = '\0';
	return (destin);
}
