/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:24:42 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/09 10:41:07 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;  //len of the str (called result)

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = (-1) * n;
		size++; //size = 1 if negative 
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}	
	return (size);
}

static void	ft_mod(int n, char *result, int size)
{
	int	mod;
	
	if (n == 0 && size == 1 && result[0] != '-') //when n = 0, size = 1
		result[0] = '0';
	if (n < 0)
	{
		n = n * (-1);
		result[0] = '-'; // if negative, put - at the beginning
	}
	if (n != 0)  // possibly add size > 0 if there are problems with francinette
		         // when n = 0, size = 0
	{
		ft_mod(n / 10, result, size - 1); //why [size-1]? recursion!
		mod = n % 10 + '0';
		result[size - 1] = mod;
	}	
}

char	*ft_itoa(int n)
{
	char	*result;
	int	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		size = ft_size(n);
		result = malloc(sizeof(char) * (size + 1)); //+1 for '\0'!
		if (result == 0)
			return (NULL);
		ft_bzero(result, size + 1); // put '\0' till the ned of the string
		ft_mod(n, result, size);
	}
	return (result);
}
