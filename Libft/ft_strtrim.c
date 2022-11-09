/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:48:42 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/09 14:36:45 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	char	*src;
	int	len;
	int	i;
	int	k;

	len = ft_strlen(s1);
	src = (char *)s1;
	i = 0;
	while (ft_check(src[i], set)) // remove set characters from left to right
		i++;              //i si e fermato quando sono finiti i caratteri di set
	while ((len - 1) > 0 && ft_check(src[len - 1], set)) // remove set characters 
		len--;                                  //from right to left. 
										  //> 0 because src[0] has been already 
										  //checked in the previous while loop
	
	if ((len - i) < 0) //if all characters of set were removed, 
		len = i;       //i.e. len = 0 and i becomes negative
	                   // to make malloc with size = 1 for '\0'
	dst = malloc(sizeof(char) * (len - i + 1));
	if (dst == 0)
		return (NULL);
	k = 0;
	while (i < len)
		dst[k++] = src[i++];
	dst[k] = '\0';
	return (dst);
}
// NULL is a pointer to 0, "" is a void string 

// second while: l'ordre est de gauche a droite. very important! if len - 1 > 0,
// we skip the second part of the condition after &&




/*
 Previous tentatives

		if (src[0] != set[i] || src[len - 1] != set[i])
		{
			dst[j] = src[j];
			j++;
		}
		else
		{
			j = 1;
			while (j < len)
			{
				dst[j] = src[j];
				j++;
			}
		}
		i++;
	}
*/
