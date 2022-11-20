/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:05:23 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/20 16:45:45 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//all int (signed int) became unsigned
//like itoa but without conditions if n < 0, because insigned int is always positive
//I don't need to convert because it's automatically done

static int	ft_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	if (n == 0)
		return (1);
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
	if (n != 0)
	{
		ft_mod(n / 10, result, size - 1);
		mod = n % 10 + '0';
		result[size - 1] = mod;
	}	
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char		*result;
	unsigned int	size;

	size = ft_size(n);
	result = malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (NULL);
	ft_bzero(result, size + 1);
	ft_mod(n, result, size);
	return (result);
}
