/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:22:54 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/08 11:34:43 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 strchr stops when it hits a null character but memchr does not;
 this is why the former does not need a length parameter but the latter does
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((unsigned char *)s + i); // finds c and returns all the *s
		i++;
	}
	return (NULL);
}
/*
 notation detail:

 (unsigned char *)s + i
     =
 str = (unsigned char *)s;
 str[i]
*/
