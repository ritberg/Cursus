/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:54:32 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/09 11:10:46 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *s = "This is a sentence"
 start = 5, len  4

output: "is a"

similar to strnstr, but return has limits - start and len
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*src;
	size_t	i;
	size_t	j;

	src = (char *)s;
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (src[j])
	{
		if (j >= start && i < len)
		{
			dst[i] = src[j];
			i++;
		}
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
// when 18446744073709551615 is tested, memory problems (MKO error)
