/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:24:42 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 11:40:57 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//all int (signed int) became unsigned

static int	ft_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = (-1) * n;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}	
	return (size);
}

static void	ft_mod(unsigned int n, char *result, unsigned int size)
{
	unsigned int	mod;

	if (n == 0 && size == 1 && result[0] != '-')
		result[0] = '0';
	if (n < 0)
	{
		n = n * (-1);
		result[0] = '-';
	}
	if (n != 0)
	{
		ft_mod(n / 10, result, size - 1);
		mod = n % 10 + '0';
		result[size - 1] = mod;
	}	
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*result;
	unsigned int		size;

	size = ft_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (NULL);
	ft_bzero(result, size + 1);
	ft_mod(n, result, size);
	return (result);
}
