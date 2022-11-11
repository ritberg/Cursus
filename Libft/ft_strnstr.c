/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:38:53 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/09 11:28:07 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Strnstr looks for needle in the first len characters of haystack. Return - all the string after spotted characters

// general idea: needle is compared to haystack from haystack[0]. when a character differs, it starts from haystack[1]. If needle dsn't correspond again, it starts from haystack[2] etc.  

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0'\
				&& i + j < len) //internal while loop. The first round i + j = 0 and j = 0; the second round i + j = 1 and j = 1; the third i + j = 3, j = 3 etc. 
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++; // if haystack character != needle character, we start from haystack[1], haystack[2] etc. and compare with needle[0], needle[1], etc. If not, we start from haystack[2], haystack{3} etc. and compare to needle{0], needle[1] etc.
		j = 0;
	}
	return (NULL);
}
/*
in the second while I added i+j < len for the test:

ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)

here 15 characters are "lorem ipsum dol" 
In this case i+j > len and the function returns null
*/
