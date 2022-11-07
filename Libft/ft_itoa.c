/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:24:42 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/07 17:36:40 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;  //len of the str (called result)

	if (n < 0)
	{
		n = (-1) * n;
		size = 1; //size starts from 1 if negative 
	}
	else
		size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}	
	return (size);
}

static void	ft_mod(int n, char *result, int size)
{
	int	mod;
	
	if (n < 0)
	{
		n = n * (-1);
		result[0] = '-'; // if negative, put - at the beginning
	}
	if (n != 0)  // possibly add size > 0 if there are problems with francinette
	{
		ft_mod(n / 10, result, size - 1); //why [size-1]? recursion!
		mod = n % 10 + '0';
		result[size] = mod; //[size] because we start from size - 1, then size - 2 etc (recursion!)
	}	
}

char	*ft_itoa(int n)
{
	char	*result;
	int	size;

	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	else
	{
		size = ft_size(n);
		result = malloc(sizeof(char) * (size + 1)); //+1 for '\0'!
		if (result == 0)
			return (NULL);
		ft_mod(n, result, size - 1); //why not size? cf. above
		result[size] = '\0'; //why not size? cf. above
	}
	return (result);
}
