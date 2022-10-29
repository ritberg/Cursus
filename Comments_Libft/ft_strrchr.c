/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:59:03 by mmakarov          #+#    #+#             */
/*   Updated: 2022/10/29 13:20:05 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 - it's better to do incrementation because when we do reverse (s--), we don't stop at the beginning of the string (the end is '\0' and the beginning is 's[0]').  That's what I had before:

char	*ft_strrchr(const char *s, int c)
{
	while (*s != '\0')
		s++;
	while (*s != (char)c)
	{
		s--;
		if (*s == '\0')
			return (0);
	}
	return ((char *)s);
}
*/

// That what I have now:

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != (char)c && i >= 0)
	{
		i--;
		if (i < 0)
			return (0);
	}
	return ((char *)(s + i));
}

// To stop at the beginning of a string, I use i >= 0 (the first character is s[0]).
// For the same reason there is the condition if (i < 0) return 0.
// The return in the end: a pointer + an integer. It means "parcours la chaîne, en incrémentant de i jusqu'au \0"
