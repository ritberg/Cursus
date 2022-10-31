/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:54:32 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/31 17:02:55 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;
	unsigned int	i;

	src = (char *)s;
	dst = malloc(len + 1); // no sizeof(* str) is needed because dst will be a part of src
	if (dst == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
