/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:14:11 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/07 13:44:23 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	ft_function(unsigned int i, char c) //delete before submission!!!!
{  
	printf("index %d for character %c\n", i, c);
	return (c - 32);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i]) //the same as while (i < ft_strlen(s))
	{
		str[i] = f(i, s[i]); // f is a pointer to ft_function, because the the main we pass ft_function as input of ft_strmapi. f(i, s[i]) corresponds to ft_function. str[i] = output of ft_function
		i++;
	}
	str[i] = '\0';
	return (str);
}
