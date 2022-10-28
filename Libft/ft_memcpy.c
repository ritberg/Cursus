/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:56:54 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/28 18:58:54 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
